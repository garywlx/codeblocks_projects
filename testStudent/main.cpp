#include <iostream>
#include <string>
#include <cassert>
using namespace std;

using arrT=int[10];

int (*func(int n))[10]
{
    arrT myarr;
    for(int i=1;i<=n;i++)
        myarr[i]=i*i;
    return &myarr;

}
void print(string word,int threshold)
{
    #ifndef ndebug
        if(word.size()<threshold)
            cerr << "Error: " << __FILE__
                << " :in function " << __func__
                << " at line " << __LINE__ << endl
                << " Compiled on " << __DATE__
                << " at " << __TIME__ << endl;
     #endif // ndebug
}
int main()
{
    typedef int arr[10];
    arr arr2;
    arrT arr3;
    int* p[10];
    int (*p2)[10]=func(10);

    for(int i=0;i<10;i++)
    {
        cout << *(*p2+i) << ends;
    }
    cout << endl;
    //string s("li");
    //print(s,10);
    //while(cin >>s && s!="sought"){}
    assert(cin);
    int a,i=0;
    char s;
    while(cin >> a)
    {
        arr3[i++]=a;
    }
    for (int j=0;j<i;j++)
        cout << arr3[i] << endl;
    return 0;
}
