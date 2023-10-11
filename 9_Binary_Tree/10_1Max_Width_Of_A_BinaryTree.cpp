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
    int MaxWidth(Node *p)
    {
        if(p==NULL)
        return 0;

        queue<pair<Node*,int>>q;
        q.push({p,0});
        int first=0;
        int last=0;
        int width=0;
        while(!q.empty())
        {
            int n=q.size();
            int mini=q.front().second;
            for(int i=1;i<=n;i++)
            {
                int curr_i=q.front().second-mini;
                p=q.front().first;
                q.pop();
                if(i==1)
                first=curr_i;
                if(i==n)
                last=curr_i;

                if(p->leftchild!=NULL)
                {
                    q.push({p->leftchild,2*curr_i+1});
                }
                if(p->rightchild!=NULL)
                {
                    q.push({p->rightchild,2*curr_i+2});
                }
            }
        width=max(width,(last-first)+1);
        }
    return width;
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
    cout<<M.MaxWidth(bt.root);
    
return 0;
}