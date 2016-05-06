#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    if((fp=fopen("test.bmp","rb")==NULL){
       printf("the file is not openned!\n");
    }
    exit(1);
    return 0;
}
