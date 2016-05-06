#include <iostream>
#include<stdlib.h>
using namespace std;
void forwardCompare(char *str1,char *str2,int len1,int len2,int *score1,int *score2)
{
    int i,flag=0;
    for(i=0;i<len1&&i<len2;i++){
        if(str1[i]==str2[i])
            continue;
        else if(str1[i]>str2[i]){
            (*score1)++;
            flag=1;
            break;
        }else if(str1[i]<str2[i]){
            (*score2)++;
            flag=1;
            break;
        }
    }
    if(flag==0){
        if(len1>len2)
            (*score1)++;
        else if(len1<len2)
            (*score2)++;
    }
}
void backCompare(char *str1,char *str2,int len1,int len2,int *score1,int *score2)
{
    int i,j,flag=0;
    for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--){
        if(str1[i]==str2[i])
            continue;
        else if(str1[i]>str2[j]){
            (*score1)++;
            flag=1;
            break;
        }else if(str1[i]<str2[j]){
            (*score2)++;
            flag=1;
            break;
        }
    }
    if(flag==0){
        if(i>=0&&j<0)
            (*score1)++;
        else if(j>=0&&i<0)
            (*score2)++;
    }
}
void middleCompare(char *str1,char *str2,int len1,int len2,int *score1,int *score2)
{
    int i,j;
    i=len1/2;
    j=len2/2;
    if(str1[i]>str2[j])
        (*score1)++;
    else if(str1[i]<str2[j])
        (*score2)++;
}
int main()
{
    //cout << "Hello world!" << endl;i
    int len1,len2,score1=0,score2=0;
    char *str1,*str2;
    cin >> len1;
    str1=new char[len1];
    cin  >> str1;
    cin  >> len2;
    str2=(char *)malloc(sizeof(char)*len2);
    cin >>str2;


    forwardCompare(str1,str2,len1,len2,&score1,&score2);
    backCompare(str1,str2,len1,len2,&score1,&score2);
     middleCompare(str1,str2,len1,len2,&score1,&score2);
    if(score1==score2)
        cout << "str1 = str2"<< endl;
    else if(score1>score2)
        cout << "str1 > str2"<< endl;
    else if(score1<score2)
        cout << "str1 < str2"<< endl;
    return 0;
}
