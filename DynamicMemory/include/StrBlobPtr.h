#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include <string>

#include "StrBlob.h"

using namespace std;

class StrBlob;

class StrBlobPtr
{
    public:
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        string& deref()const;
        StrBlobPtr& incre();//Ç°×ºµÝÔö
        virtual ~StrBlobPtr();

    protected:

    private:
        shared_ptr<vector<string>> check(size_t,const string&)const;
        weak_ptr<vector<string>> wptr;
        size_t curr;
};

#endif // STRBLOBPTR_H
