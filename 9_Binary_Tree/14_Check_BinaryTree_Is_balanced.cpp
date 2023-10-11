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
    int Height(Node *p,int &l,int &r)
    {
        if(p==NULL)
        return 0;

        int left=Height(p->leftchild,l,r);
        int right=Height(p->rightchild,l,r);

        l=left;
        r=right;
        return 1+ max(left,right);
    }

    bool CheckheightbalanceBT(Node *root)
    {
        int l,r;
        Height(root,l,r);
        
        if(l==r)
        return true;

        return false;
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
    cout<<M.CheckheightbalanceBT(bt.root);
    
return 0;
}