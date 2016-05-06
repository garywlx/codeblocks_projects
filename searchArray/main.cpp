#include <iostream>
#include <stdlib.h>
//#include <math.h>
using namespace std;

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Partition(int arr[],int start,int end)
{
    int random = rand()%(end - start + 1) + start;
    int val=arr[random];
    Swap(&arr[start],&arr[random]);
    while(start<end){
        while(start<end&&arr[end]>val) end--;
        if(start<end)
            arr[start++]=arr[end];
        while(start<end&&arr[start]<val) start++;
        if(start < end)
            arr[end--]=arr[start];
    }
    arr[start]=val;
    return start;

}
int main()
{
    int i,length;
    cin >> length;
    int arr[length];

    for(i=0;i<length;i++)
        cin >> arr[i];

    if(length<=1)
    {
        cout << "the input array contains only one number" << endl;
        return 0;
    }
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(arr, start, end);
    while(index!=middle){
        if(index>middle){
            end=index-1;
            index=Partition(arr, start, end);
        }else{
            start=index+1;
            index=Partition(arr, start, end);
        }
    }
    int Count=0;
    int val=arr[middle];
    for(i=0;i<length;i++){
        if(arr[i]==val)
            Count++;
    }
    if(Count>middle)
        cout << "The number is "<< val << endl;
    else
        cout << "there is no number meets the above condition" << endl;
    return 0;
}
