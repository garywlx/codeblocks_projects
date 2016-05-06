#include <iostream>

using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int x):val(x),next(NULL){}
};
void CreateCircleLinkList(Node *root,int n)
{
    Node *p=root;
    for(int i=1;i<n;i++){
        Node *t=new Node(i);
        p->next=t;
        p=t;
    }
    p->next=root;
}
int main()
{
    int n,m;
    cin >> n >> m;
    if(n<=0||m<=0){
        return 0;
    }
    Node *root=new Node(0);
    CreateCircleLinkList(root,n);
    while(root->next!=root){
        for(int i=1;i<m-1;i++){
            root=root->next;
        }
        Node *tmp=root->next;
        root->next=tmp->next;
        root=root->next;
        delete tmp;
    }
    cout << root->val << endl;
    return 0;
}
