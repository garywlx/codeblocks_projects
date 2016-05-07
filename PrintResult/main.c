#include <stdio.h>
#include <stdlib.h>

//1.the function result is ?
void myString(char *buffer)
{
    int i;
    char s[]="Hello World!";
    for(i=0;i<sizeof(s);i++)
    {
        buffer[i]=*(s+i);
    }

}
int main()
{
    char buffer[20];
    myString(buffer);
    printf("%s",buffer);
    return 0;
}
