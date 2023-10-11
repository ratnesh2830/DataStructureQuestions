#include<iostream>
using namespace std;
#include<vector>

struct Node
{
    Node *leftchild;
    int data;
    Node *rightchild;
};

class BinarySearchTree
{
    public:
    Node *CreateBSTRecursive(Node  *p,int key) //recursive way
        {
          Node *temp;
          if(p==NULL)
          {
             temp=new Node;
             temp->data=key;
             temp->leftchild=temp->rightchild=NULL;
             return temp;
           }
           if(key<p->data)
           {
            p->leftchild=CreateBSTRecursive(p->leftchild,key);
           }
           else if(key>p->data)
           {
            p->rightchild=CreateBSTRecursive(p->rightchild,key);
           }
        
        return p;
        }

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

    void traversal(Node *p)
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            traversal(p->leftchild);
            traversal(p->rightchild);
        }
    }
};  

int main()
{
    BinarySearchTree bst;
    Node *root=NULL;
    root=bst.CreateBSTIterative(root,9);
    bst.CreateBSTIterative(root,15);
    bst.CreateBSTIterative(root,5);
    bst.CreateBSTIterative(root,20);
    bst.CreateBSTIterative(root,16);
    bst.CreateBSTIterative(root,8);
    bst.CreateBSTIterative(root,12);
    bst.CreateBSTIterative(root,3);
    bst.CreateBSTIterative(root,6);
    bst.traversal(root);    
return 0;
}