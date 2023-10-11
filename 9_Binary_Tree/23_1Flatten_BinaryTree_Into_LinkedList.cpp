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
    Node * prev=NULL;

    void FlattenBinaryTree(Node *p) //using recursion
    {
        if(p==NULL)
        return;

        FlattenBinaryTree(p->rightchild);
        FlattenBinaryTree(p->leftchild);

        p->rightchild=prev;
        p->leftchild=NULL;
        prev=p;
    
    
    }
   
   void FlattenBT(Node *p) //Iterative method
   {
    if(p==NULL)
    return;

    stack<Node*>st;
    st.push(p);
    while(!st.empty())
    {
        p=st.top();
        st.pop();

        if(p->rightchild!=NULL)
        st.push(p->rightchild);

        if(p->leftchild!=NULL)
        st.push(p->leftchild);

        if(!st.empty())
        {
            p->rightchild=st.top();
        }
        p->leftchild=NULL;
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
    M.FlattenBinaryTree(bt.root);
    while(bt.root!=NULL)
    {
        cout<<bt.root->data<<" ";
        bt.root=bt.root->rightchild;
    }
return 0;
}