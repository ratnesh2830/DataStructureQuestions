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
    vector<vector<int>> Zigzagtraversal(Node *p)
    {
        vector<vector<int>>res;
        if(p==NULL)
        return res;

        queue<Node *>q;
        q.push(p);
        bool lefttoright=true;
        while(!q.empty())
        {
        int n=q.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            p=q.front();
            q.pop();
            int index=lefttoright?i:n-i-1;
            vec[index]=p->data;
            if(p->leftchild!=NULL)
            {
                q.push(p->leftchild);
            }
            if(p->rightchild!=NULL)
            {
                q.push(p->rightchild);
            }
        }    
        lefttoright=!lefttoright;
        res.push_back(vec);        
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
    vector<vector<int>>res=M.Zigzagtraversal(bt.root);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
    cout<<endl;
    }
return 0;
}