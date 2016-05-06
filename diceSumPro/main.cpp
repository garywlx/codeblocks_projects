#include <iostream>
#include <vector>

using namespace std;

void findNumber(int diceNum,int sum,int &foundNum){
    if(diceNum==0){
        if(sum==0){

            foundNum++;
        }
    }else{
        for(int i=1;i<=6;i++){
            findNumber(diceNum-1,sum-i,foundNum);
        }
    }
}
int main()
{
    vector<int> arr(10,1);
    cout << "Hello world!" << endl;
    int n,sum;
    cin >> n;
    for(int i=n;i<=6*n;i++){
        int foudNum=0;
        findNumber(n,i,foudNum);
        cout << "Sum: " << i << " Propability:" << foudNum << endl;
    }
    return 0;
}
