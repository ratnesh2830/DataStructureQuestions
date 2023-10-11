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
   int KthSmallestBST(Node *p,int k)
   {
        int count =0;
        int res=-1;
        if(p==NULL || k<1)
        return res;
        stack<Node*>st;
        while(true)
        {
            if(p!=NULL)
            {
                st.push(p);
                p=p->leftchild;
            }
            else
            {
                if(st.empty()==true)
                break;

                p=st.top();
                st.pop();
                if(count!=k)
                {
                    count++;
                    res=p->data;
                }
                else
                break;
                p=p->rightchild;
            }
        }
        if(k>count)
        return -1;

    return res;
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
    Solution M;
    vector<int>vec={6,2,8,0,12,7,9,3,5};
    Node *root=NULL;
    root=bst.CreateBSTIterative(root,vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        bst.CreateBSTIterative(root,vec[i]);
    }
    cout<<M.KthSmallestBST(root,0);
    
return 0;
}