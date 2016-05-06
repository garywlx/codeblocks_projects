#include <iostream>
#include <stdio.h>
#include <malloc.h>
//#define NULL 0
using namespace std;
struct Node{
    int value;
    struct Node *next;
    struct Node *random;
};
Node *deepCopy(Node *head){
    struct Node *p=head,*q=head->next,*newNode=NULL;

    //插入节点
    while(p!=NULL){
        newNode =(Node *)malloc(sizeof(struct Node));
        newNode->value=p->value;
        newNode->next=p->next;
        p->next=newNode->next;
        p=q;
        q=q->next;
    }
    //初始化随机索引
    p=head;
    while(p!=NULL){
        p->next->random=p->random->next;
        p=p->next->next;
    }
    //分开节点
    p=head;
    newNode=q=head->next;
    while(p!=NULL){
        p->next=q->next;
        q->next=p->next;
        p=p->next;
        q=q->next;
    }
    return newNode;
}
int main()
{
    //cout << "Hello world!" << endl;
    char hello[]="hello";
    printf("%d",sizeof(hello));
    int n;
    scanf("%d",&n);
    if(n<=0)
        return 0;
    int F[n+1];
    F[1]=1;
    F[2]=2;
    for(int i=3;i<=n;i++){
        if(n==1){
                printf("%d",F[1]);
             return 0;
        }
        else if(n==2){
            printf("%d",F[2]);
            return 0;
        }
        else{
            F[i]=F[i-1]+F[i-2];
        }
    }
    printf("%d",F[n]);
    return 0;
}
