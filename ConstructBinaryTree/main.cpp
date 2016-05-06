#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* constructBinaryTree(vector<int> pre,vector<int> in,
                                     int preleft, int preright,int inleft,int inright)
{
    int val = pre[preleft];
    TreeNode *root=new TreeNode(val);
    if(preleft==preright){
        if(inleft==inright&&pre[preleft]==in[inleft])
            return root;
        else
            return NULL;
    }
    int i,j;
    for(i=inleft; in[i]!=val&&i<=inright; i++);
       // midIndex++;
    if(i==inright&&in[i]!=val)
        return NULL;
    int leftlength=i-inleft;
    TreeNode *left,*right;
    if(leftlength>0)
    {
        root->left=constructBinaryTree(pre,in,preleft+1,preleft+leftlength,inleft,inleft+leftlength-1);
    }
    if(leftlength<preright-preleft)
    {
        root->right=constructBinaryTree(pre,in,preleft+leftlength+1,preright,inleft+leftlength+1,inright);
    }
    //root->left=left;
    //root->right=right;
    return root;
}

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
{

    struct TreeNode* head;
    if(pre.empty()||in.empty()||pre.size()!=in.size())
        return NULL;

    head=constructBinaryTree(pre,in,0,pre.size()-1,0,in.size()-1);
    return head;
}
int IsBanlanced(TreeNode *root,int &balanced)
{
    if(root==NULL){
        return 0;
    }
    else{
        int left=IsBanlanced(root->left,balanced);
        int right=IsBanlanced(root->right,balanced);
        if(left-right>1||right-left>1){
            balanced=0;
        }
        return 1+(left > right ? left:right);
    }

}
int main()
{
    //cout << "Hello world!" << endl;
    vector<int> pre{1,2,4,7,3,5,6,8};
    vector<int> in{4,7,2,1,5,3,8,6};
    struct TreeNode *head=new TreeNode(10);
    struct TreeNode *p1=new TreeNode(23);
    struct TreeNode *p2=new TreeNode(4);
    struct TreeNode *p3=new TreeNode(34);
    struct TreeNode *p4=new TreeNode(41);
    head->left=p1;
    p1->left=p2;
    //p2->left=p3;
    head->right=p4;
    p4->left=p2;
    //head=reConstructBinaryTree(pre,in);
    int balanced=1;
    IsBanlanced(head,balanced);
    if(balanced)
    {
        cout << "Balanced." << endl;
    }else{
        cout << "Not balanced" << endl;
    }
    return 0;
}
