#include<stdio.h>
int cstrcmp(char *p1,char *p2);

int main()
{
    char a[20];
    char b[20];
    int c,m,n,i;
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        scanf("%c",&a[i]);
    }
    scanf("%d",&m);
    getchar();
    for(i=0; i<m; i++)
    {
        scanf("%c",&b[i]);
    }

    c=cstrcmp(a,b);

}

int cstrcmp(char *p1,char *p2)
{
    int i=0;
    for(i=0; i<20; i++)
    {
        if(*p1>*p2)
        {
            return 1;
            break;
        }
        else if(*p1<*p2)
        {
            return -1;
            break;
        }
        else
        {
            p1++;
            p2++;
            if(*p1=='\0'&&*p2=='\0')
                return 0;
            else;
        }
    }
}

