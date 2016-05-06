//#include <iostream>
#include <stdio.h>
//using namespace std;
int findMaxLCS(int a,int b){
    //int t;
    if(a>b)
        return findMaxLCS(a-b,b);
    else if(a<b)
        return findMaxLCS(a,b-a);
    else
        return a;
}
int findMaxLCS1(int a,int b){
    int tmp;
    while(b!=0){
        tmp=b;
        b=a%b;
        a=b;
    }
    return a;
}
int main()
{
    int n,init,sum;
    //cin >> n >> init;
    while(scanf("%d%d",&n,&init)!=EOF){
        //scanf("%d%d",&n,&init);
        if(n<1||n>=100000)
            return 0;
        int abilits[n];
        for(int i=0;i<n;i++){
            //cin >> abilits[i];
            scanf("%d",&abilits[i]);
            if(abilits[i]<1||abilits[i]>=100000)
                return 0;
        }
        sum=init;
        for(int i=0;i<n;i++)
        {
            if(sum>abilits[i])
                sum += abilits[i];
            else
                sum += findMaxLCS1(sum,abilits[i]);
        }
        //cout << sum << endl;
        printf("%d\n",sum);
    }
    return 0;
}
