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
    Node *next;
};

class Solution
{
    public:
    void PopulateNextRightPointers(Node *p)
    {
        if(p==NULL)
        return;

        queue<Node*>q;
        q.push(p);
        while(!q.empty())
        {
            int n=q.size();
            Node* prev=q.front();
            prev->next=NULL;
            for(int i=0;i<n;i++)
            {
                p=q.front();
                q.pop();
                if(i!=0)
                {
                    p->next=prev;
                    prev=p;
                }
                if(p->rightchild)
                q.push(p->rightchild);

                if(p->leftchild)
                q.push(p->leftchild);
            }
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
    M.PopulateNextRightPointers(bt.root);
    cout<<bt.root->leftchild->leftchild->next->next->data;
return 0;
}