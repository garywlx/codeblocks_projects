//#include <iostream>
#include <stdio.h>
#include <ctype.h>
//using namespace std;

int main()
{
    char c,uc;
    int i,j,len;
    //printf("Input a charactor:");
    scanf("%c",&c);
    if(isalpha(c)){
        uc=toupper(c);
        len=uc - 'A' + 1;
    }else{
        printf("Invalid character!");
        return 0;
    }
    //printf("\n");
    for(i=0;i<len;i++){
        int numOfPace=len-i-1;
        for(j=0;j<numOfPace;j++)
            printf(" ");
        for(j=0;j<=i;j++){
            char tmp='A' + j;
            printf("%c",tmp);
        }
        for(j=i-1;j>=0;j--){
            char tmp='A' + j;
            printf("%c",tmp);
        }
        printf("\n");
    }
    //cout << "Hello world!" << endl;
    return 0;
}
