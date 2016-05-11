#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10000
struct person *Insert(struct person *head);
void Print(struct person *head);
struct person*Delete(struct person *head,char d[n]);
struct person
{
    char name[n];
    char num[n];
    struct person *next;
};
int main()
{
    char a[]= {"Insert"},b[]= {"Print"},c[]= {"End"},d[n],e[n];
    struct person*head=NULL;
    while(true)
    {
        scanf("%s",e);
        if(strcmp(e,a)==0)
            head=Insert(head);
        else if(strcmp(e,b)==0)
            Print(head);
        else if(strcmp(c,e)==0)
        {
            exit(0);
        }
        else
        {
            scanf("%s",d);
            head=Delete(head,d);
        }
    }
}
struct person *Insert(struct person *head)
{
    char NAME[n],m[n];
    struct person *tr=head,*t=head;
    t=(struct person*)malloc(sizeof(struct person));
    scanf("%s %s %s %s\n",t->name,t->num,m,NAME);
    t->next=NULL;
    if(t==NULL)
    {
        exit(0);
    }
    if(head==NULL)
    {
        head=t;
    }
    else
    {
        while((strcmp(NAME,tr->name)!=0)&&tr->next!=NULL)
        {
            tr=tr->next;
        }
        if(strcmp(NAME,tr->name)==0&&t!=NULL)
        {
            t->next=tr->next;
            tr->next=t;
        }
        else if(strcmp(NAME,tr->name)!=0&&t!=NULL)
        {
            t->next=head;
            head=t;
        }
    }
return head;
}
void Print(struct person *head)
{
    struct person*t=head;
    while(t!=NULL)
    {
        printf("%s %s\n",t->name,t->num);
        t=t->next;
    }
}
struct person*Delete(struct person *head,char d[n])
{
    struct person *t=head,*tr=head;
    if(head==NULL)
    {
        return(head);
    }
    while(t!=NULL&&(strcmp(t->name,d)!=0))
    {
        tr=t;
        t=t->next;
    }
    if(t==NULL){
        //exit(0);
    }
    else if(strcmp(d,t->name)==0)
    {
        if(t==head)
        {
            head=t->next;
        }
        else
        {
            tr->next=t->next;
        }
        free(t);
    }

    return head;

}
