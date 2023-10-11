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

class Solution
{
    public:
    vector<int>Postordertraversal1(Node *p)
    {
        static vector<int>res;
        if(p!=NULL)
        {
            Postordertraversal1(p->leftchild);
            Postordertraversal1(p->rightchild);
            res.push_back(p->data);
        }
    return res;
    }

    vector<int>Postordertraversal(Node *p)
    {
        stack<Node*>st1,st2;
        vector<int>res;
        if(p==NULL)return res;
        st1.push(p);
        while(!st1.empty())
        {
            p=st1.top();
            st2.push(p);
            st1.pop();
            if(p->leftchild!=NULL)
            {
                st1.push(p->leftchild);
            }
            if(p->rightchild!=NULL)
            {
                st1.push(p->rightchild);
            }
        }
        while(!st2.empty())
        {
            res.push_back(st2.top()->data);
            st2.pop();
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
    vector<int>res=M.Postordertraversal(bt.root);
    for(auto i:res)
    {
        cout<<i<<" ";
    }


return 0;
}