//#include <iostream>
#include <stdio.h>
//using namespace std;

int Min(int num1,int num2,int num3)
{
    int min = (num1<num2) ? num1 : num2;
    min = (min<num3) ? min : num3;
    return min;
}
int GetUglyNumber(int index)
{
    int *pUglyNumbers=new int[index];
    pUglyNumbers[0]=1;
    int nextUglyIndex=1;
    int *pMultiply2=pUglyNumbers;
    int *pMultiply3=pUglyNumbers;
    int *pMultiply5=pUglyNumbers;
    while(nextUglyIndex<index)
    {
        int min=Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
        pUglyNumbers[nextUglyIndex]=min;
        while(*pMultiply2*2<=pUglyNumbers[nextUglyIndex])pMultiply2++;
        while(*pMultiply3*3<=pUglyNumbers[nextUglyIndex])pMultiply3++;
        while(*pMultiply5*5<=pUglyNumbers[nextUglyIndex])pMultiply5++;
        nextUglyIndex++;
    }
    int ugly=pUglyNumbers[nextUglyIndex-1];
    delete[] pUglyNumbers;
    return ugly;

}
int isUgly(int num)
{
    while(num%2==0) num=num/2;
    while(num%3==0) num=num/3;
    while(num%5==0) num=num/5;
    return (num ==1) ? 1:0;
}
int GetUglyNumber2(int index)
{
    int number=0;
    int finded=0;
    while(finded<index)
    {
        number++;
        if(isUgly(number))
            finded++;
    }
    return number;
}
int main()
{
    //cout << "Hello world!" << endl;
    int index;
    //cin >> index;
    scanf("%d",&index);
    if(index<0)
        return 0;
    //cout << GetUglyNumber2(index) << endl;
    printf("%d\n",GetUglyNumber(index));
    return 0;
}
