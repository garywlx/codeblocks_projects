#include <iostream>
#include "Sales_data.h"
#include <vector>
#include <string>
#include <list>
#include "DeleteDebug.h"
#include "shared_pointer.h"

using namespace std;

template<typename T>
int compare(const T &v1,const T &v2)
{
    if(v1<v2)return -1;
    if(v2<v1)return 1;
    return 0;
}

template<typename InputIterator,typename T>
InputIterator find(InputIterator first,InputIterator last,const T &val)
{
    while(first!=last){
        if(*first==val)
            return first;
        ++first;
    }
    return last;
}
template<typename T,unsigned N>
void print(const T (&arr)[N])
{
    for(auto elem:arr)
        cout << elem <<ends;
    cout <<endl;
}

template<typename T, unsigned size>
constexpr unsigned getSize(const T(&)[size])
{
    return size;
}
template<typename Container>
ostream &print(const Container &C,ostream &os)
{
    typedef typename Container::size_type size_type;
    auto it=C.begin();
    for(size_type i=0;i!=C.size();i++)
    {
        os << *it++ <<ends;
    }
    os <<endl;
    return os;
}

template<typename Container>
ostream &print2(const Container &C,ostream &os)
{
    for(auto it=C.begin();it!=C.end();it++)
    {
        os << *it <<ends;
    }
    os <<endl;
    return os;
}
template<typename It>
auto func(It beg,It end)->decltype(*beg)
{
    return *beg;
}

template<typename T>
auto sum(T lhs, T rhs) -> decltype( lhs + rhs)
{
    return lhs + rhs;
}
//传递左值时直接转化为左值引用
template<typename T>
void ref_func(T &&i)
{
    i++;
}
template <typename T> void f(T)
{
    std::cout << "f(T)\n";
}

template <typename T> void f(const T*)
{
    std::cout << "f(const T*)\n";
}
template <typename T> void g(T)
{
    std::cout << "template <typename T> void g(T)\n";
}
template <typename T> void g(T*)
{
    std::cout << "template <typename T> void g(T*)\n";
}

int main()
{
    /**
    cout << "Hello world!" << endl;
    //Sales_data a,b;
    cout << compare(1,1)<< endl;
    vector<int> vi{10,23,24,23,3,2,2,3,3,53};
    list<string> ls={"li","quan","xin"};
    auto index=find(vi.begin(),vi.end(),10);
    cout << *index <<endl;
    char a[]="s";
    cout << getSize(a) <<endl;
    print(vi,cout);
    print2(ls,cout);
    DeleteDebug d;
    int *p=new int;
    d(p);*/
    shared_pointer<int> sp(new int);
    shared_pointer<int> sp1(sp);
    shared_pointer<int> sp2(std::move(sp));
    shared_pointer<int> sp3=std::move(sp2);
    shared_pointer<int> sp4=sp3;
    sp4.reset();
    cout << sp1.use_count()<< endl;
    //cout << sp2.use_count()<< endl;
    cout << sp3.use_count()<< endl;
    //cout << sp4.use_count()<< endl;
    auto result=sum(1235234564623521351,123491385125612394);
    cout << result <<endl;
    //int i=5;
    //int &&ri=std::move(i);
    //cout << i <<endl;
    //cout << ri <<endl;
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);    //template <typename T> void g(T ); --is called
    g(p);     //template <typename T> void g(T*); --is called
    g(ci);      //template <typename T> void g(T)   --is called
    g(p2);      //template <typename T> void g(T*)    --is called
    f(42);    //f(T)
    f(p);     //f(T)
    f(ci);    //f(T)
    f(p2);      //f(const T*)
    return 0;
}
