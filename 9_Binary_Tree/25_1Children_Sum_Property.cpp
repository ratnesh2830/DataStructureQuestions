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
    void ChildrenSumProperty(Node *p)
    {
        if(p==NULL)
        return;

        int child=0;
        if(p->leftchild)
        child+=p->leftchild->data;
        if(p->rightchild)
        child+=p->rightchild->data;

        if(child>=p->data)
        p->data=child;
        else
        {
            if(p->leftchild)
            p->leftchild->data=p->data;
            if(p->rightchild)
            p->rightchild->data=p->data;
        }

        ChildrenSumProperty(p->leftchild);
        ChildrenSumProperty(p->rightchild);

        int total=0;
        if(p->leftchild)
        total+=p->leftchild->data;
        if(p->rightchild)
        total+=p->rightchild->data;
        if(p->leftchild && p->rightchild)
        p->data=total;
    }
    void traversalpre(Node *p)
    {
      if(p!=NULL)
       {
        cout<<p->data<<" ";
        traversalpre(p->leftchild);
        traversalpre(p->rightchild);
       }
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
    M.ChildrenSumProperty(bt.root);
    M.traversalpre(bt.root);
return 0;
}