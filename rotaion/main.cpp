#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isPrime(int x){
    int i,flag=1;
    if(x<=1) return 0;
    for(i=2;i<=sqrt(x)&&flag;i++){
        if(x%i==0)
            flag=0;
    }
    return flag;
}
int isPalindrome(int x){
    char str[20];
    int i,j,flag=1;
    if(x<0) return 0;
    //itoa(x,str,10);
    sprintf(str,"%d",x);
    for(i=0,j=strlen(str)-1;j>=0&&flag;i++,j--){
        if(str[i]!=str[j])
            flag=0;
    }
    return flag;
}
int main()
{
    int i,a,b;
    scanf("%d%d",&a,&b);
    if(a>=b)
        return 0;
    for(i=a;i<=b;i++){
        if(isPalindrome(i)&&isPrime(i))
            printf("%d\n",i);
    }
    return 0;
}
