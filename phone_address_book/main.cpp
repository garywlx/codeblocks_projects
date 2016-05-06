#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DATA
{
    char name[21];
    char phone[21];
    struct DATA *next;
};

struct DATA *Insert(struct DATA* start);
struct DATA *Delete(struct DATA* start);
void Print(struct DATA* start);

int main()
{
    struct DATA *start = NULL;
    char operation[7];
    while (1)
    {
        scanf("%s",operation);
        if (!strcmp(operation,"End"))
            break;
        else if (!strcmp(operation,"Insert"))
        {
            start = Insert(start);
//            flag++;
//            if (!flag)
//            {
//                pstart = start;
//            }
//            printf("%p\n",start);
            continue;
        }
        else if (!strcmp(operation,"Delete"))
        {
            start = Delete(start);
            continue;
        }
        else if (!strcmp(operation,"Print"))
        {
            Print(start);
            continue;
        }
    }
    return 0;
}

struct DATA *Insert(struct DATA* start)
{
    char behind[21];
    struct DATA *p=NULL, *pr=start;
    while (p==NULL)
    {
        p = (struct DATA*)malloc(sizeof(struct DATA));
    }
    scanf("%s %s %s %s",p->name,p->phone,behind,behind);
    p->next = NULL;
    if (!strcmp(behind,"Nobody"))
    {
        p->next = start;
        start = p;
        return start;
    }
    while(strcmp(pr->name,behind))
    {
        pr = pr->next;
    }
    p->next = pr->next;
    pr->next = p;
    return start;
}

struct DATA *Delete(struct DATA* start)
{
    char name[21];
    struct DATA *pr=start, *p=start;
    scanf("%s",name);
    while(strcmp(p->name,name))
    {
        pr = p;
        p = p->next;
    }
    if (p==start)
        start = p->next;
    else
    {
        pr->next = p->next;
    }
    free(p);
    return start;
}

void Print(struct DATA* start)
{
    struct DATA *p=start;
    while (p!=NULL)
    {
        printf("%s %s\n",p->name,p->phone);
        p = p->next;
    }
}
