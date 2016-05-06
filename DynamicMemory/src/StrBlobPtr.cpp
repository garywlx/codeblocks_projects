#include "StrBlobPtr.h"

shared_ptr<vector<string>> StrBlobPtr::check()(size_t i,const string &msg)const
{
    auto ret=wptr.lock();
    if(!ret)
        throw runtime_error("unbounded StrBkibPtr!");
    if(i>=ret->size())
        throw out_of_range(msg);
    return ret;
}
string& StrBlobPtr::deref()const
{
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incre()
{
    check(curr,"increment past end of StrBlobPtr");
    curr++;
    return *this;
}
StrBlobPtr::~StrBlobPtr()
{
    //dtor
}
