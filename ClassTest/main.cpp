#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class Base
{
    int x;
public:
    Base(int b):x(b){}
    virtual void display()
    {
        cout << "x=" << x << endl;
    }

    virtual void private_test()
    {
        cout << "base private virtual fucntion." << endl;
    }
};
class Derived:public Base
{
    int y;
public:
    Derived(int d):Base(d),y(d){}
    void display()
    {
        cout << "y="<< y << endl;
    }
    void private_test()
    {
        cout << "Derived private_test virtual fucntion." << endl;
    }
};
struct tom{
    long long x1;
    char x2;
    int x3;
    char x4;
    static int x5;
};
void FormatString(char str[],int n)
{
    int i,j=0;
    while(str[j]==' '){
        j++;
    }
    for(i=0;j<n;){
        while(str[j]!=' ' && j<n){
            str[i++]=str[j++];
        }
        while(str[j]==' ' && j<n){
            j++;
        }
        str[i++]=' ';
    }
    str[i-1]='\0';
    cout << string(str);
}
int main()
{
    //char str[1000];
    //cout << "Input a string:" << endl;
    //cin >> str;
    //cin.getline(str,1000);
    //FormatString(str,strlen(str));
    Base *b=new Derived(3);
    b->private_test();
    return 0;
}
