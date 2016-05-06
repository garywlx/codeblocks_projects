#include "String.h"

String::String(char *p)
{
    char *q=p;
    while(*q!='\0')q++;
    auto data=alloc_n_copy(p,q);
    __first=data.first;
    __end=__cap=data.second;
    //cout << "Called copy construct function!" << endl;
}

String::String(const String &rhs)
{
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    __first=data.first;
    __end=__cap=data.second;
    cout << "Called copy construct function!" << endl;
}
String::String(String &&s)noexcept:__first(s.__first),__end(s.__end)
{
    s.__first = s.__end = nullptr;
    cout << "Called move construct function!" << endl;
}
String& String::operator=(const String &s)
{
    auto data=alloc_n_copy(s.begin(),s.end());
    free();
    __first=data.first;
    __end=__cap=data.second;
    cout << "Called copy equal operator function!" << endl;
    return *this;

}
String& String::operator=(String &&rhs)noexcept
{
    /**
    auto newdata=alloc.allocate(s.begin()-s.end());
    auto last=uninitialized_copy(make_move_iterator(s.begin()),make_move_iterator(s.end()),newdata);
    free();
    __first=newdata;
    __end=__cap=last;
    */
    if (this != &rhs) {
        free();
        __first = rhs.__first;
        __end = rhs.__end;
        rhs.__first = rhs.__end = nullptr;
    }
    cout << "Called move equal operator function!" << endl;
    return *this;

}
void String::append(const String &s)
{
    size_t cursize=size()+s.size();
    while(cursize>size())
    {
        reallocate();
    }
    auto dst=end();
    for(char *p=s.begin(); p!=s.end(); p++)
    {
        alloc.construct(dst++,std::move(*p));
    }
    __end=dst;

}
void String::push_back(const String &s)
{
    append(s);
}
String& String::operator+=(const String &s)
{
    append(s);
    return *this;
}
String& String::operator+=(char *str)
{
    String s=String(str);
    append(s);
    return *this;
}
char& String::operator[](const size_t index)
{
    auto tt = index<0?0:index;
    tt = index>=size()?size()-1:index;
    return *(__first+tt);
}
void String::clear()
{
    if(__first)
        for_each(__first, __end, [this](char &c)
    {
        alloc.destroy(&c);
    });
}
void String::erase(size_t pos,size_t len)
{

}
pair<char*,char*> String::alloc_n_copy(const char *b,const char *e)
{
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}
void String::free()
{
    if(__first)
    {
        for_each(__first, __end, [this](char &c)
        {
            alloc.destroy(&c);
        });
        alloc.deallocate(__first,__cap-__first);
    }
}
void String::reallocate()
{
    auto newcap=size()?size()*2:1;
    auto newdata=alloc.allocate(newcap);
    auto dst=newdata;
    auto p=__first;
    for(size_t i=0; i!=size(); i++)
        alloc.construct(dst++,std::move(*p++));
    __first=newdata;
    __end=dst;
    __cap=__first+newcap;

}

ostream &operator<<(ostream &os,const String &s)
{
    auto c = s.c_str();
    while (*c) os << *c++;
    return os;
}

bool operator==(const String &lhs,const String &rhs)
{
    return (lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const String &a,const String &b)
{
    return !(a==b);
}
String::~String()
{
    //dtor
    free();
}
