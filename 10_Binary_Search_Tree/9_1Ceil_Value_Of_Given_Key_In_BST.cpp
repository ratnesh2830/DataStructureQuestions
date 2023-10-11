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
    int CeilValue(Node *p,int key)
    {
        int ceil=-1;
        if(p==NULL)
        return ceil;

        while(p!=NULL)
        {
            if(p->data==key)
            {
                ceil=p->data;
                return ceil;
            }
            else if(p->data > key)
            {
                ceil=p->data;
                p=p->leftchild;
            }
            else
            {
                p=p->rightchild;
            }
        }
    return ceil;
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
};




int main()
{
    BinarySearchTree bst;
    vector<int>vec={6,2,8,0,12,7,9,3,5};
    Node *root=NULL;
    root=bst.CreateBSTIterative(root,vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        bst.CreateBSTIterative(root,vec[i]);
    }
    Solution M;
    cout<<M.CeilValue(root,5);
return 0;
}