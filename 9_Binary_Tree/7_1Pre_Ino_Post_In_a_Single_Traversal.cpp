#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>
#include<map>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};

class Solution
{
    public:
  void PreInPostTraversal(Node *p,vector<int>&pre,vector<int>&Ino,vector<int>&post)
   {
        if(p==NULL)
        return;

        stack<pair<Node*,int>>st;
        st.push({p,1});
        while(!st.empty())
        {
            p=st.top().first;
            int value=st.top().second;
            st.pop();

            if(value==1)
            {
                st.push({p,value+1});
                pre.push_back(p->data);
                if(p->leftchild!=NULL)
                {
                    st.push({p->leftchild,1});
                }
            }
            else if(value==2)
            {
                st.push({p,value+1});
                Ino.push_back(p->data);
                if(p->rightchild!=NULL)
                {
                    st.push({p->rightchild,1});
                }
            }
            else if(value==3)
            {
                post.push_back(p->data);
            }
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
    vector<int>Pre,Ino,Post;
    M.PreInPostTraversal(bt.root,Pre,Ino,Post);
    for(auto i:Pre)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:Ino)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:Post)
    {
        cout<<i<<" ";
    }

return 0;
}