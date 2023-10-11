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
    int FloorValue(Node *p,int key)
    {
        int floor=-1;//it means no floor value is present in the BST which is lessthan or equal to given key
        if(p==NULL)
        return -1;  

        while(p!=NULL)
        {
            if(p->data==key)
            {
                floor=p->data;
                return floor;
            }
            else if(p->data>key)
            {
                p=p->leftchild;
            }
            else
            {
                floor=p->data;
                p=p->rightchild;
            }
        }
    return floor;

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
    cout<<M.FloorValue(root,13);
return 0;
}