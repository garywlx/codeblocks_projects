#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

typedef struct BiNode{
    int val;
    BiNode *left=NULL;
    BiNode *right=NULL;
}BiTree;

BiTree* CreateBiTree()
{
    BiTree* head =(BiTree*)malloc(sizeof(BiTree));
    head->val=1;
    BiTree* A =(BiTree*)malloc(sizeof(BiTree));
    A->val=2;
    BiTree* B =(BiTree*)malloc(sizeof(BiTree));
    B->val=3;
    head->left=A;
    head->right=B;
    BiTree* C =(BiTree*)malloc(sizeof(BiTree));
    C->val=4;
    BiTree* D =(BiTree*)malloc(sizeof(BiTree));
    D->val=5;
    D->left=D->right=NULL;
    A->left=C;
    A->right=D;
    BiTree* E =(BiTree*)malloc(sizeof(BiTree));
    E->val=7;
    E->left=E->right=NULL;
    BiTree* F =(BiTree*)malloc(sizeof(BiTree));
    F->val=8;
    F->left=F->right=NULL;
    B->left=E;
    B->right=F;
    BiTree* G =(BiTree*)malloc(sizeof(BiTree));
    G->val=9;
    G->left=G->right=NULL;
    C->left=G;
    return head;
}
/**
  先序遍历
*/

void preOrderTree(BiTree *head)
{
    if(head==NULL) return;
    stack<BiTree*> s;
    BiTree *p=head,*preVisit=NULL;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            cout << p->val << " ";
            p=p->left;
        }
        if(!s.empty()){
            p=s.top();s.pop();
            p=p->right;
        }

    }
}
/**
中序遍历
*/
void inOrderTree(BiTree *head)
{
    if(head==NULL) return;
    stack<BiTree*> s;
    BiTree *p=head,*preVisit=NULL;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
        if(!s.empty()){
            p=s.top();s.pop();
            cout << p->val << " ";
            p=p->right;
        }

    }
}
/**
后序遍历
*/
void postOrderTree(BiTree *head)
{
    if(head==NULL) return;
    stack<BiTree*> s;
    BiTree *p=head,*preVisit=NULL;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
        if(!s.empty()){
            p=s.top();s.pop();
            if(p->right==NULL || p->right==preVisit){
                cout << p->val << " ";
                preVisit=p;
                p=NULL;
            }else{
                s.push(p);
                p=p->right;
            }
        }

    }
}
int main()
{
    BiTree* root=CreateBiTree();
    cout << "Pre Order:" << endl;
    preOrderTree(root);
    cout << endl;
    cout << "In Order:" << endl;
    inOrderTree(root);
    cout << endl;
    cout << "Post Order:" << endl;
    postOrderTree(root);
    return 0;
}
