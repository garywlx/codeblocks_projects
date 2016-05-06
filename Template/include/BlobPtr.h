#ifndef BLOBPTR_H
#define BLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "Blob.h"

using namespace std;

template <typename T> class Blob;

template<typename T>
class BlobPtr
{
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T>& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const BlobPtr& p)
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
    BlobPtr& incr()
    {
        check(curr, "increment past end of BlobPtr");
        ++curr;
        return *this;
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    BlobPtr &operator+=(size_t);
    BlobPtr &operator-=(size_t);
    BlobPtr operator+(size_t) const;
    BlobPtr operator-(size_t) const;

private:
    std::shared_ptr<vector<string>> check(size_t i, const string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound BlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};
template<typename T>
inline BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr,"increment past end of BlobPtr");
    ++curr;
    return *this;

}
template<typename T>
inline BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr,"decrement past begin of BlobPtr");
    return *this;
}
template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret=*this;
    ++*this;
    return ret;
}
template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret=*this;
    --*this;
    return ret;
}
template<typename T>
inline BlobPtr<T> &BlobPtr<T>::operator+=(size_t n)
{

    curr += n;
    check(curr, "increment past end of BlobPtr");
    return *this;
}
template<typename T>
inline BlobPtr<T> &BlobPtr<T>::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of BlobPtr");
    return *this;
}
template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
    BlobPtr ret = *this;
    ret += n;
    return ret;
}
template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
    BlobPtr ret = *this;
    ret -= n;
    return ret;
}

#endif // BLOBPTR_H
