#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <algorithm>
using namespace std;

class StrVec
{
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
public:

    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(StrVec &&s)noexcept:elements(s.elements),first_free(s.first_free),cap(s.cap)
    {
        s.elements=s.first_free=s.cap=nullptr;
    }
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec &&s)noexcept;
    StrVec& operator=(initializer_list<string>);
    string& operator[](size_t n){return elements[n];}
    const string& operator[](size_t n)const{return elements[n];}
    void push_back(const string &);
    void reverse();
    void resize(size_t,const string &s=string());
    void m_destroy(string &rhs);
    size_t size()const{return first_free-elements;}
    size_t capacity()const{return cap-elements;}
    string *begin()const {return elements;}
    string *end()const {return first_free;}
    virtual ~StrVec();

protected:

private:
    allocator<string> alloc;
    void chk_n_alloc(){if(size()==capacity()) reallocate();}
    pair<string*,string*> alloc_n_copy(const string*,const string*);
    void free();//销毁元素并释放内存
    void reallocate();//获得更多内存并释放已有元素
    string *elements;
    string *first_free;
    string *cap;
};
bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
#endif // STRVEC_H
