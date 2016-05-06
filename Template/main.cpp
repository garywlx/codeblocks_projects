#include <iostream>
#include "Sales_data.h"
#include <vector>
#include <string>

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
int main()
{
    cout << "Hello world!" << endl;
    //Sales_data a,b;
    cout << compare(1,1)<< endl;
    vector<int> vi{10,23,24,23,3,2,2,3,3,53};
    auto index=find(vi.begin(),vi.end(),10);
    cout << *index <<endl;
    char a[]="s";
    cout << getSize(a) <<endl;
    return 0;
}
