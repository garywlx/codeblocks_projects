#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu
{
    //Stu():name(""),phone(""),next(nullptr){}
    char name[21];
    char phone[21];
    struct Stu *next;
};
Stu *head=NULL;
void Insert()
{
    Stu *t=(Stu*)malloc(sizeof(Stu));
    printf("Input a stu info: \n");
    scanf("%s%s",t->name,t->phone);
    t->next=NULL;
    if(head==NULL){
        head=t;
        head->next=NULL;
    }
    else
    {
        Stu *p=head;
        while(p->next!=NULL)
            p=p->next;
        p->next=t;
    }

}
void print(){
    Stu *p=head;
    while(p!=NULL){
        printf("%s %s\n",p->name,p->phone);
        p=p->next;
    }
}
void delete_(char *name)
{
    Stu *p=head,*pre=NULL;
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0){
            if(pre!=NULL)
            {
                pre->next=p->next;
                delete p;
            }else{
                head=p->next;
                delete p;
            }
            break;
        }
        pre=p;
        p=p->next;
    }
    print();
}

int main()
{
    for(int i=0;i<3;i++)
    {
        Insert();
    }
    print();
    for(int i=0;i<10;i++)
    {
        char name[20];
        printf("INput a name to delted:\n");
        scanf("%s",name);
        delete_(name);
    }
    return 0;
}
