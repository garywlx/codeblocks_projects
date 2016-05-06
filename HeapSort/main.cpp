#include <iostream>
#include <stdio.h>

using namespace std;

void AdjustHeap(int *arr,int i,int len)
{
    int maxIndex=i;
    int left=2*i,right=2*i+1;
    if(left<=len&&arr[left]>arr[maxIndex])
        maxIndex=left;
    if(right<=len&&arr[right]>arr[maxIndex])
        maxIndex=right;
    if(maxIndex!=i){
        swap(arr[i],arr[maxIndex]);
        AdjustHeap(arr,maxIndex,len);
    }

}
void BuildHeap(int *arr,int len)
{
    for(int i=len/2;i>=1;i--){
        AdjustHeap(arr,i,len);
    }
}
void HeapSort(int *arr,int len)
{
    BuildHeap(arr,len);
    for(int i=len;i>1;i--){
        swap(arr[1],arr[i]);
        AdjustHeap(arr,1,i-1);
    }

}
int main()
{
    cout << "Hello world!" << endl;
    int arr[100],i=1;
    char ch;
    while(1){
        //cin>> arr[i++] >> ch;
        scanf("%d%c",&arr[i++],&ch);
        if(ch=='\n')
            break;
    }
    HeapSort(arr,i-1);
    for(int j=1;j<i;j++)
        cout << arr[j] << " ";
    return 0;
}
