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
    void Invert(Node *p)
    {
        if(p!=NULL)
        {
            Invert(p->leftchild);
            Invert(p->rightchild);

            Node *temp=p->leftchild;
            p->leftchild=p->rightchild;
            p->rightchild=temp;
        }
    }
    void traversal(Node *p)
    {
        if(p!=NULL)
        {
            traversal(p->leftchild);
            traversal(p->rightchild);
            cout<<p->data<<" ";
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
    M.Invert(bt.root);
    M.traversal(bt.root);
return 0;
}