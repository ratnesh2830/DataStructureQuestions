#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};

class Solution
{
    public:
    Node* LowestCommonAncestor(Node *root,Node *p,Node *q)
    {
        if(root==NULL || root==p || root==q)
        return root;

        Node *left=LowestCommonAncestor(root->leftchild,p,q);
        Node *right=LowestCommonAncestor(root->rightchild,p,q);

        if(left==NULL)
        return right;

        else if(right==NULL)
        return left;

        else
        return root;
    }
   
};


class BinaryTree
{
    public:
    Node *root=NULL;

    void CreateBT()
    {
    int x;
    cout<<"enter the root node value"<<endl;
    cin>>x;
    root=new Node;
    root->data=x;
    root->leftchild=root->rightchild=NULL;
    queue<Node*>q;
    q.push(root);
    Node *p;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"enter left child of "<<p->data<<endl;;
        cin>>x;
        if(x!=-1)
        {
            Node *temp=new Node;
            temp->data=x;
            temp->leftchild=temp->rightchild=NULL;
            p->leftchild=temp;
            q.push(temp);
        }
        cout<<"enter the right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            Node *temp=new Node;
            temp->data=x;
            temp->leftchild=temp->rightchild=NULL;
            p->rightchild=temp;
            q.push(temp);
        }
    }

    }

};

int main()
{
    BinaryTree bt;
    bt.CreateBT();
    Solution M;
    Node *p=M.LowestCommonAncestor(bt.root,bt.root->rightchild,bt.root->rightchild->rightchild);
    cout<<p->data;
return 0;
}