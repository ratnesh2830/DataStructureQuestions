#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};


class NewNode
{
    public:
    int min,max,size;

    NewNode(int min,int max,int size)
    {
        this->min=min;
        this->max=max;
        this->size=size;
    }
};


class Solution
{
    public:

    NewNode Check(Node *p)
    {
        if(p==NULL)
        {
            return NewNode(INT_MAX,INT_MIN,0);
        }

        NewNode left=Check(p->leftchild);
        NewNode right=Check(p->rightchild);

        if(left.max<p->data && p->data<right.min)
        {
            return NewNode(min(left.min,p->data),max(p->data,right.max),left.size+right.size+1);
        }
        
    return NewNode(INT_MIN,INT_MAX,max(left.size,right.size));
    }

    int LargestBSTsizeInBT(Node *root)
    {
        NewNode a=Check(root);
        return a.size;
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
    cout<<M.LargestBSTsizeInBT(bt.root);
    
return 0;
}