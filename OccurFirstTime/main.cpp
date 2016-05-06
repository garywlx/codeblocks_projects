#include <iostream>

using namespace std;
unsigned int FindFrstBitIs1(int num)
{
    int indexBit=0;
    while(((num & 0x1)==0)&&(indexBit<8*sizeof(int)))
    {
        num=num>>1;
        indexBit++;
    }
    return indexBit;
}
bool isBit1(int num,int index)
{

    num=num>>index;
    return (num&1);
}
void FindNumberAppearOnce(int *a,int n,int &num1,int &num2)
{
    if(a==NULL||n<2)
        return;
    int resultExcusiveOR=0;
    for(int i=0;i<n;i++)
        resultExcusiveOR^=a[i];
    unsigned int index=FindFrstBitIs1(resultExcusiveOR);
    for(int i=0;i<n;i++){
        if(isBit1(a[i],index))
            num1^=a[i];
        else
            num2^=a[i];
    }
}

void print(int i,int k){
    cout << i << "~" << k << endl;
}
void findContinues(int s)
{
    int len=(s+1)>>1;
    int k=1;
    while(k<len){
        int i=k;
        int curSum=i;
        while(curSum<s){
            i++;
            curSum+=i;
        }
        if(curSum==s){
            print(k,i);
        }
        k++;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    findContinues(150);
    return 0;
}
