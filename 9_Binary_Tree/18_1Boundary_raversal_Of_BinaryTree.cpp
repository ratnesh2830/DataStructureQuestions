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
    bool isleafnode(Node *p)
    {
        if(p->leftchild==NULL &&p->rightchild==NULL)
        return true;
    
    return false;
    }
    void leftnodes(Node *root,vector<int>&res)
    {
        Node *cur=root->leftchild;
        while(cur!=NULL)
        {
            if(!isleafnode(cur))
            res.push_back(cur->data);
            if(cur->leftchild!=NULL)
            cur=cur->leftchild;
            else
            cur=cur->rightchild;
        }
    }

    void leafnodes(Node *p,vector<int>&res)
    {
        if(isleafnode(p))
        {
            res.push_back(p->data);
        }
        if(p->leftchild!=NULL)
        leafnodes(p->leftchild,res);
        if(p->rightchild!=NULL)
        leafnodes(p->rightchild,res);
    }

    void rightnodes(Node *root,vector<int>&res)
    {
        Node *cur=root->rightchild;
        vector<int>vec;
        while(cur!=NULL)
        {
            if(!isleafnode(cur))
            vec.push_back(cur->data);
            if(cur->rightchild!=NULL)
            cur=cur->rightchild;
            else
            cur=cur->leftchild;
        }
        for(int i=vec.size()-1;i>=0;i--)
        {
            res.push_back(vec[i]);
        }
    }
    vector<int>BoundaryTraversal(Node *root)
    {
        vector<int>res;
        if(root==NULL)
        return res;
        if(!isleafnode(root))
        {
            res.push_back(root->data);
        }
        leftnodes(root,res);
        leafnodes(root,res);
        rightnodes(root,res);
    
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
    vector<int>res=M.BoundaryTraversal(bt.root);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
return 0;
}