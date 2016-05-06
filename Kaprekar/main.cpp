//#include <iostream>
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
//#include<string.h>
//using namespace std;
int compare1 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int compare2 (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}
int digitsOfNumber(int x){
    char strNum[20];
    sprintf(strNum,"%d",x);
    return strlen(strNum);
}
int m_pow(int len){
    int s=1;
    for(int i=1;i<=len;i++){
        s=s*10;
    }
    return s;
}

int findMax(int x,int digits){
    int a[20];
    //char str[10];
    int i=0,j=0;
    while(x!=0){
        a[i++]=x%10;
        x/=10;
    }
    qsort (a, i, sizeof(int), compare1);
    int sum = 0;
    for(j=0;j<i;j++){
        int t=m_pow(j);
        //printf("Max:%d\n",t);
        sum += t*a[j];
    }
    int len=digitsOfNumber(sum);
    while(len<digits){
        sum*=10;
        len++;
    }
    return sum;
}

int findMin(int x){
    int a[20];
    //char str[10];
    int i=0,j=0;
    while(x!=0){
        a[i++]=x%10;
        x/=10;
    }
    qsort (a, i, sizeof(int), compare2);
    int sum=0;
    for(j=0;j<i;j++){
        int t=m_pow(j);
        //printf("Min:%d\n",t);
        sum += t*a[j];
    }
    return sum;
}

int main()
{
    //cout << "Hello world!" << endl;
    int x;
    scanf("%d",&x);
    int len=digitsOfNumber(x);
    int diff=0;
    do{
        int minVal,maxVal;
        maxVal=findMax(x,len);
        minVal=findMin(x);
        diff=maxVal-minVal;
        if(diff!=x){
            printf("%d-%d=%d\n",maxVal,minVal,diff);
            x=diff;
            //diff=0;
        }else
            break;
    }while(1);
    printf("The blackhole number is %d.",x);
    return 0;
}
