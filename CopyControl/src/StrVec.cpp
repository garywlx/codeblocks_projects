#include "StrVec.h"

//StrVec::alloc;

StrVec::StrVec(const StrVec &v)
{
    auto newdata=alloc_n_copy(v.begin(),v.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}

pair<string*,string*> StrVec::alloc_n_copy(const string *b,const string *e)
{
    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}
void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

void StrVec::reverse()
{
    auto be=begin();
    auto ed=end()-1;
    while(be!=ed)
    {
        swap(*be,*ed);
        be++;
        ed--;
    }
}

void StrVec::resize(size_t m_size,const string &s)
{
    //chk_n_alloc();
    if(m_size<size())
    {
        auto dst=end();
        while(dst-begin()>m_size)
        {
            alloc.destroy(--dst);
        }
        alloc.deallocate(dst,cap-dst);
        first_free=dst;
    }
    else if(m_size>size() && m_size <=capacity())
    {
        auto dst=end();
        while(dst-begin()<m_size)
        {
            alloc.construct(dst++,s);
        }
        first_free=dst;
    }
    else if(m_size > capacity())
    {
        while(m_size>capacity())
        {
            reallocate();
        }
        auto dst=end();
        while(dst-begin()<m_size)
        {
            alloc.construct(dst++,s);
        }
        first_free=dst;
    }

}
StrVec& StrVec::operator=(StrVec &&s)noexcept
{
    if(this!=&s)
    {
        free();
        elements=s.elements;
        first_free=s.first_free;
        cap=s.cap;
        s.elements=s.first_free=s.cap=nullptr;
    }
    return *this;

}
StrVec& StrVec::operator=(const StrVec &v)
{
    auto newdata=alloc_n_copy(v.begin(),v.end());
    free();
    elements=newdata.first;
    first_free=cap=newdata.second;
    return *this;
}

StrVec& StrVec::operator=(initializer_list<string> il)
{
    auto newdata=alloc_n_copy(il.begin(),il.end());
    free();
    elements=newdata.first;
    first_free=cap=newdata.second;
    return *this;
}
void StrVec::free()
{
    if(elements)
    {
        /**
                for(auto p=first_free;p!=elements;)
                {
                    alloc.destroy(--p);
                }*/
        for_each(elements, first_free, [this](string &s)
        {
            alloc.destroy(&s);
        });
        alloc.deallocate(elements,cap-elements);
    }
}
/**
void StrVec::m_destroy(string &rhs)
{
    alloc.destroy(&rhs);
}
*/
void StrVec::reallocate()
{
    auto newcap=size()?2*size():1;
    auto newdata=alloc.allocate(newcap);
    //auto dst=newdata;
    //auto elem=elements;
    //for(size_t i=0;i!=size();i++){
    //    alloc.construct(dst++,std::move(*elem++));
    //}
    auto last =uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),newdata);
    free();
    elements=newdata;
    first_free=last;
    cap=elements+newcap;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    return (lhs.size() == rhs.size() &&
            std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs==lhs);
}
StrVec::~StrVec()
{
    //dtor
    free();
}
