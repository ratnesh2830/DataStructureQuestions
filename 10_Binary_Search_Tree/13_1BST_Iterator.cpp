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

class BSTiterator
{
   public:
   stack<Node*>st;

   BSTiterator(Node *p)
   {
    Pushall(p);
   }

   bool hasnext()
   {
        if(st.empty())
        return false;

    return true;
   }

   int Next()
   {
    Node *temp=st.top();
    st.pop();
    Pushall(temp->rightchild);
    return temp->data;
   }

   private:

   void Pushall(Node *p)
   {
    while(p!=NULL)
    {
        st.push(p);
        p=p->leftchild;
    }
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

    BSTiterator M(root);  
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.hasnext()<<" ";
    cout<<M.Next()<<" ";
    cout<<M.hasnext()<<" ";

return 0;
}