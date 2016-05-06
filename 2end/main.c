#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    int x;
    int y;
}point;
double findDis(point a,point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int main()
{
    point p0,p1,p2,p3;
    //int tmp;
    int R,sum=0;
    scanf("%d%d%d%d%d%d%d%d%d",&R,&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p0.x,&p0.y);
    if(findDis(p1,p0)<=R)
        sum++;
    if(findDis(p2,p0)<=R)
        sum++;
    if(findDis(p3,p0)<=R)
        sum++;
    printf("%dx",sum);
    return 0;
}
