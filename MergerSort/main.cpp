#include <iostream>

using namespace std;

void mergeArr(int *a,int low,int mid,int high,int &number)
{
    int *tmp=new int[high-low+1];
    int i,j,k=0;
    for(i=low,j=mid+1;i<=mid&&j<=high;)
    {
        if(a[i]<=a[j]){
            tmp[k++]=a[i++];
        }
        else{
            tmp[k++]=a[j++];
            number+=(mid-i+1);
        }
    }
    while(i<=mid){
        tmp[k++]=a[i++];
    }
    while(j<=high){
        tmp[k++]=a[j++];
    }
    for(i=low,j=0;j<k;j++,i++)
    {
        a[i]=tmp[j];
    }

}
void m_merge(int *a,int low,int high,int &number)
{
    if(low<high)
    {
        int mid=(low+high)>>1;
        m_merge(a,low,mid,number);
        m_merge(a,mid+1,high,number);
        mergeArr(a,low,mid,high,number);
    }
}
int main()
{
    //cout << "Hello world!" << endl;
    int num=0,a[100];
    for(int i=0;i<5;i++)
        cin >> a[i];
    m_merge(a,0,4,num);
    for(int i=0;i<5;i++)
    {
        cout << a[i] << ends;
    }
    cout << endl;
    cout << num << endl;
    return 0;
}
