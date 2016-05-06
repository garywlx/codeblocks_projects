#include<stdio.h>
#include<string.h>

int f(char *str){
    int number=0;
    char tmp[200];
    strcpy(tmp,str);
    int length=strlen(tmp);
    for(int i=0;i<length-1;i++){
        if(tmp[i]=='.'&&tmp[i+1]=='.')
            number++;
    }
    return number;
}
int main()
{
    int n,m;
    char str[200];
    while(scanf("%d%d",&n,&m)!=EOF){
        //cin >> s_str;
        int i,j;
        scanf("%s",str);
        for(j=0;j<m;j++){
            int ix;
            char ch;
            scanf("%d %c",&ix,&ch);
            str[ix-1]=ch;
            printf("%d\n",f(str));
        }
    }
    return 0;
}
