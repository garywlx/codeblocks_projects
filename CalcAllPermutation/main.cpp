#include <iostream>
#include <string>

using namespace std;

void PrintPermutation(char *str,char *pStart){

    if(*pStart == '\0')
    {
        cout << str <<endl;
    }
    for(char *p=pStart;*p!='\0';p++){
        swap(*p,*pStart);
        PrintPermutation(str,pStart+1);
        swap(*p,*pStart);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    char s[]="abcd";
    PrintPermutation(s,s);
    return 0;
}
