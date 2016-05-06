#include <iostream>
#include <stdio.h>
using namespace std;

void reverse(char *pBegin,char *pEnd)
{
    if(pBegin==NULL || pEnd==NULL)
        return;
    char ch;
    while(pBegin<pEnd){
        ch=*pBegin;
        *pBegin=*pEnd;
        *pEnd=ch;
        pBegin++;
        pEnd--;
    }
}
void reverseSentence(char *pData)
{
    if(pData==NULL)
        return;
    char *p,*q;
    p=q=pData;
    while(*q!='\0')
        q++;
    q--;
    reverse(p,q);
    p=q=pData;
    while(*p!='\0'){
        if(*p==' '){
            p++;
            q++;
        }else if(*q==' '||*q=='\0'){
            reverse(p,--q);
            p = ++q;
        }else{
            q++;
        }
    }
    cout << pData <<endl;

}
void reverseSentence(string data)
{

}
int main()
{
    cout << "Hello world!" << endl;
    char s[100];
    //cin >> s;
    //getline(cin,s);
    gets(s);
    puts(s);
    reverseSentence(s);
    return 0;
}
