#include<stdio.h>

int main()
{
    long long n,b;
    while(scanf("%lld%lld",&n,&b)!=EOF){
        int t,diff;
        int x=n/2;
        if(b>x){
            diff=b-x;
            t=x-diff+1;
        }else if(b<x){
            diff=x-b;
            t=x+diff-1;
        }else{
			t=b;
        }
        printf("%d\n",t);
    }
    return 0;
}
