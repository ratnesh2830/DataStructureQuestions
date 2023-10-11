#include<iostream>
using namespace std;
#include<vector>

struct Node
{
    Node *leftchild;
    int data;
    Node *rightchild;
};

class Solution
{
    public:

    Node *SearchInBstRecursive(Node *p,int key)
    {
        if(p==NULL)
        return NULL;

        if(key==p->data)
        {
            return p;
        }

        if(key<p->data)
        {
            return SearchInBstRecursive(p->leftchild,key);
        }
        else if(key>p->data)
        {
            return SearchInBstRecursive(p->rightchild,key);
        }
    return NULL;
    }


    Node *SearchInBstIterative(Node *p,int key)
    {
        if(p==NULL)
        return NULL;

        while(p!=NULL)
        {
            if(key==p->data)
            return p;
            
            else if(key<p->data)
            p=p->leftchild;

            else
            p=p->rightchild;
        }
    return NULL;
    }
};

class BinarySearchTree
{
    public:
    Node *CreateBST(Node  *p,int key)
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
            p->leftchild=CreateBST(p->leftchild,key);
           }
           else if(key>p->data)
           {
            p->rightchild=CreateBST(p->rightchild,key);
           }
        
        return p;
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
    vector<int>vec={9,15,5,20,16,8,12,3,6};
    Node *root=NULL;
    root=bst.CreateBST(root,vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        bst.CreateBST(root,vec[i]);
    }
    Solution M;
    int key=15;
    Node *p=M.SearchInBstIterative(root,key);
    cout<<p->data;
return 0;
}