#include<iostream>
using namespace std;
#include<vector>
#include<stack>

struct Node
{
    Node *leftchild;
    int data;
    Node *rightchild;
};

class Solution
{
    public:
    Node *InorderSuccessor(Node *p,int key)
    {
        if(p==NULL)
        return NULL;
        Node *successor=NULL;
        while(p!=NULL)
        {
            if(p->data<=key)
            {
                p=p->rightchild;
            }
            else
            {
                successor=p;
                p=p->leftchild;
            }
        }
    return successor;
    }
    
    Node *InorderPredecessor(Node *p,int key)
    {
        if(p==NULL)
        return NULL;
        Node *successor=NULL;
        while(p!=NULL)
        {
            if(p->data<key)
            {
                successor=p;
                p=p->rightchild;
            }
            else
            {
                p=p->leftchild;
            }
        }
    return successor;
    }
};

class BinarySearchTree
{
    public:
    Node *CreateBSTIterative(Node *p,int key) //iterative way
    {
        Node *r=NULL,*temp=NULL;
        if(p==NULL)
        {
            temp=new Node;
            temp->data=key;
            temp->leftchild=temp->rightchild=NULL;
            return temp;
        }
        while(p!=NULL)
        {
            r=p;

            if(key<p->data)
            {
                p=p->leftchild;
            }
            else if(key>p->data)
            {
                p=p->rightchild;
            }
        }
        temp=new Node;
        temp->data=key;
        temp->leftchild=temp->rightchild=NULL;
    
      if(key>r->data)
      r->rightchild=temp;
      else if(key<r->data)
      r->leftchild=temp;

    return NULL;
    }

    void preordertraversal(Node *p)
     {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            preordertraversal(p->leftchild);
            preordertraversal(p->rightchild);
        }
     }
};




int main()
{
    BinarySearchTree bst;
    vector<int>vec={6,2,8,0,4,7,9,3,5};
    Node *root=NULL;
    root=bst.CreateBSTIterative(root,vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        bst.CreateBSTIterative(root,vec[i]);
    }

    Solution M;
    Node *LCA=M.InorderSuccessor(root,4);
    cout<<LCA->data<<endl;
    LCA=M.InorderPredecessor(root,4);
    cout<<LCA->data;
return 0;
}