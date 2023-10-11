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
    int HeightBT(Node *p)
    {
        if(p==NULL)
        return 0;

        queue<Node*>q;
        q.push(p);
        int height=0;
        while(!q.empty())
        {
            height++;
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                p=q.front();
                q.pop();
                if(p->leftchild!=NULL)
                {
                    q.push(p->leftchild);
                }
                if(p->rightchild!=NULL)
                {
                    q.push(p->rightchild);
                }
            }
        }
    return height;
    }

    int HeightBTrecursive(Node *p)
    {
        if(p==NULL)
        return 0;

        int left=HeightBTrecursive(p->leftchild);
        int right=HeightBTrecursive(p->rightchild);
        return 1+ max(left,right);
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
    cout<<M.HeightBTrecursive(bt.root);
return 0;
}