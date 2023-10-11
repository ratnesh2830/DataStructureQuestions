#include<iostream>
using namespace std;
#include<vector>
#include<queue>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};

class Solution
{
    public:
    bool Getpath(Node *p,vector<int>&res,int x)
    {
        if(p==NULL)
        return false;

        res.push_back(p->data);
        if(p->data==x)
        return true;

        if(Getpath(p->leftchild,res,x)||Getpath(p->rightchild,res,x))
        return true;

        res.pop_back();
        return false;
    }

    vector<int>Path(Node *root,int x)
    {
        vector<int>res;

        Getpath(root,res,x);
    return res;
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
    vector<int>res;
    res=M.Path(bt.root,70);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}