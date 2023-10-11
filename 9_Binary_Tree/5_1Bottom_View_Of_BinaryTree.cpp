#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>
#include<map>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};

class Solution
{
    public:

   vector<int>Bottomview(Node *p)
   {
    vector<int>res;
    if(p==NULL)
    return res;

    queue<pair<Node*,int>>q;
    map<int,int>map;
    q.push({p,0});
    while(!q.empty())
    {
        p=q.front().first;
        int line=q.front().second;
        q.pop();
        map[line]=p->data;
        if(p->leftchild!=NULL)
        {
            q.push({p->leftchild,line-1});
        }
        if(p->rightchild!=NULL)
        {
            q.push({p->rightchild,line+1});
        }
    }

    for(auto it:map)
    {
        res.push_back(it.second);
    }
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
    vector<int>res=M.Bottomview(bt.root);
    for(auto i:res)
    {
        cout<<i<<" ";
    }


return 0;
}