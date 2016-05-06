#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

class String
{
    friend ostream& operator<<(ostream &os,const String &s);
    friend bool operator==(const String&,const String&);
    friend bool operator!=(const String&,const String&);
    public:
        String():__first(nullptr),__end(nullptr),__cap(nullptr){}
        String(char *p);
        String(const String&);
        String(String &&)noexcept;
        String& operator=(const String&);
        String& operator=(String &&)noexcept;
        void push_back(const String&);
        String& operator+=(const String&);
        String& operator+=(char *str);
        char& operator[](const size_t index);
        void clear();
        bool empty(){return (__end-__first)==0? true:false;}
        void erase(size_t pos=0,size_t len=1);
        char* begin()const{return __first;}
        char* end()const{return __end;}
        size_t size()const{return __end-__first;}
        size_t capacity()const{return __cap-__first;}
        const char* c_str() const { return __first; }
        virtual ~String();

    protected:

    private:
        allocator<char> alloc;
        void chk_n_alloc(){if(size()==capacity()) reallocate();}
        pair<char*,char*> alloc_n_copy(const char*,const char*);
        void reallocate();
        void free();
        void append(const String&);
        //char *__string;
        char *__first;
        char *__end;
        char *__cap;
};
ostream &operator<<(ostream &os,const String &s);
bool operator==(const String&,const String&);
bool operator!=(const String&,const String&);
#endif // STRING_H
