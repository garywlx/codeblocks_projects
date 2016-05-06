#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
//#include "StrBlobPtr.h"

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size()const
    {
        return data->size();
    }
    bool empty()const
    {
        return data->empty();
    }
    void push_back(const std::string &msg)
    {
        data->push_back(msg);
    }
    void pop_back();
    StrBlobPtr begin();
    StrBlobPtr end();
    std::string& front();
    std::string& back();
    std::string& front()const;
    std::string& back()const;
    virtual ~StrBlob();

protected:

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_t t,const std::string &msg)const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr& p)
    {
        return p.curr != curr;
    }
    string& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    string *operator->()const
    {
        return &(this->operator*());
    }
    StrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr &operator+=(size_t);
    StrBlobPtr &operator-=(size_t);
    StrBlobPtr operator+(size_t) const;
    StrBlobPtr operator-(size_t) const;

private:
    std::shared_ptr<vector<string>> check(size_t i, const string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};

inline StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;

}
inline StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr,"decrement past begin of StrBlobPtr");
    return *this;
}
inline StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret=*this;
    ++*this;
    return ret;
}
inline StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret=*this;
    --*this;
    return ret;
}
inline StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{

    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}
inline StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}
inline StrBlobPtr StrBlobPtr::operator+(size_t n) const
{
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}
inline StrBlobPtr StrBlobPtr::operator-(size_t n) const
{
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}
#endif // STRBLOB_H
