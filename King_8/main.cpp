#include <iostream>

using namespace std;

#define N 8

int findIndex(int a[],int n){
    int i=0;
    for(i=0;i<N;i++)
        if(a[i]==1)
            break;
    return i;
}
void Print(int a[][N])
{
    cout << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << a[i][j] << ends;
        }
        cout << endl;
    }
}
void Chess(int a[][N],int &num,int start)
{
    if(start==N-1){
        int flag=1;
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                int colI=findIndex(a[i],N);
                int colJ=findIndex(a[j],N);
                if(i-j==colI-colJ||j-i==colI-colJ){
                    flag=0;
                    break;
                }
            }
            if(flag==0)
                break;
        }
        if(flag==1){
            Print(a);
            num++;
        }

    }
    for(int i=start;i<N;i++){
        int firstIndex=findIndex(a[start],N);
        int secondIndex=findIndex(a[i],N);
        swap(a[start][firstIndex],a[start][secondIndex]);
        swap(a[i][firstIndex],a[i][secondIndex]);
        Chess(a,num,start+1);
        swap(a[start][firstIndex],a[start][secondIndex]);
        swap(a[i][firstIndex],a[i][secondIndex]);
    }
}
int main()
{
    cout << "Hello world:" << endl;
    int a[N][N]={0};
    for(int i=0;i<N;i++)
        a[i][i]=1;
    int positionNumber=0;
    Chess(a,positionNumber,0);
    cout << "Chess Nomber:" << positionNumber << endl;
    return 0;
}
