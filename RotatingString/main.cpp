//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    //getchar();
    if(n<=0 || k<0){
        printf("Input error!");
        return 0;
    }
    char str[n+1],strTmp[n+1];
    //gets(str);
    scanf("%s",str);
    k = k%n;
    j=n-k;
    for(i=0;i<k;i++){
        strTmp[j]=str[i];
        j++;
    }
    j=0;
    for(i=k;i<n;i++){
        strTmp[j]=str[i];
        j++;
    }
    strTmp[n]='\0';
    printf("%s",strTmp);
    return 0;
}
