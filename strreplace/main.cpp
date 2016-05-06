#include <iostream>
//#include <stdio.h>
//#include <string>
#include <string.h>
using namespace std;

void replaceSpace(char *str,int length)
{
    int blackNum=0,newlen=0,i=0,j;
    while(str[i]!='\0'){
         if(str[i]==' ')
            blackNum++;
         i++;
    }

    newlen = strlen(str)+2*blackNum;
    if(newlen>length)
        return;
    //char tmp[newlen+1];
    for(i=strlen(str)-1,j=newlen-1; i>=0; i--)
    {
        if(str[i]==' ')
        {
            str[j--]='0';
            str[j--]='2';
            str[j--]='%';
        }
        else
            str[j--]=str[i];
    }
    str[newlen]='\0';
    //puts(str);
    //memset(str,' ',newlen);
    //strcpy(str,tmp);
}
int main()
{
    //cout << "Hello world!" << endl;
    char name[]="We Are Happy.";
    replaceSpace(name,100);
    cout << string(name) << endl;
    return 0;
}
