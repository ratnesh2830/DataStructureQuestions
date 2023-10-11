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
    Node * traversal(Node *root,int x)
    {
        if(root==NULL)
        {
            Node *temp=new Node;
            temp->data=x;
            temp->leftchild=temp->rightchild=NULL;
            return temp;
        }
        if(x<root->data)
        root->leftchild=traversal(root->leftchild,x);

        if(x>root->data)
        root->rightchild=traversal(root->rightchild,x);
    
    return root;
    }
    Node *CreateBSTfromPreorder1(vector<int>&pre) //craeting in nlogn time naive approach
    {
        Node *root=new Node;
        int i=0;
        root->data=pre[i++];
        root->leftchild=root->rightchild=NULL;
        for(int i=1;i<pre.size();i++)
        {
            traversal(root,pre[i]);
        }
    return root;
    }


    Node * CreateBSTfromPreorder(vector<int>&pre)
    {
        if(pre.size()==0)
        return NULL;
        int i=0;
        stack<Node*>st;
        Node *root=new Node;
        root->data=pre[i++];
        root->leftchild=root->rightchild=NULL;

        Node *p=root,*t=NULL;

        while(i<pre.size())
        {
            if(pre[i]<p->data)
            {
                t=new Node;
                t->data=pre[i++];
                t->leftchild=t->rightchild=NULL;
                p->leftchild=t;
                st.push(p);
                p=t;
            }
            else
            {
                if(pre[i]>p->data && st.empty()?pre[i]<INT_MAX:pre[i]<st.top()->data)
                {
                    t=new Node;
                    t->data=pre[i++];
                    t->leftchild=t->rightchild=NULL;
                    p->rightchild=t;
                    p=t;
                }
                else
                {
                    p=st.top();
                    st.pop();
                }
            }
        }
    return root;
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
    Solution M;
    vector<int>pre={30,20,10,15,25,40,50,45};
    Node *root=NULL;
    root=M.CreateBSTfromPreorder1(pre);
    M.preordertraversal(root);
return 0;
}