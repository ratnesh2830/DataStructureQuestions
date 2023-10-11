#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

struct Node
{
    Node *leftchild;
    int data;
    Node *rightchild;
};
class Solution
{
    public:

    Node * Construct(vector<int>&Inor,int instart,int inend,vector<int>&post,int poststart,int postend,unordered_map<int,int>&map)
    {
        if(poststart>postend || instart>inend)
        return NULL;

        Node *root=new Node;
        root->data=post[postend];
        root->leftchild=root->rightchild=NULL;

        int inroot=map[post[postend]];
        int left=inroot-instart;

        root->leftchild=Construct(Inor,instart,inroot-1,post,poststart,poststart+left-1,map);
        root->rightchild=Construct(Inor,inroot+1,inend,post,poststart+left,postend-1,map);

        return root;
    }

    Node *ConstructBT(vector<int>&Inor,vector<int>&post)
    {
        unordered_map<int,int>map;
        for(int i=0;i<Inor.size();i++)
        {
            map[Inor[i]]=i;
        }
        Node *root=Construct(Inor,0,Inor.size()-1,post,0,post.size()-1,map);

        return root;
    }

    void inordertraversal(Node *p)
    {
        if(p!=NULL)
        {
            inordertraversal(p->leftchild);
            cout<<p->data<<" ";
            inordertraversal(p->rightchild);
        }
    }
    void postordertraversal(Node *p)
    {
        if(p!=NULL)
        {
            postordertraversal(p->leftchild);
            postordertraversal(p->rightchild);
            cout<<p->data<<" ";
        }
    }
    
};

int main()
{
    Solution M;
    vector<int>Inor={40,20,50,10,60,30};
    vector<int>post={40,50,20,60,30,10};
    Node *root=M.ConstructBT(Inor,post);
    M.inordertraversal(root);
    cout<<endl;
    M.postordertraversal(root);
return 0;
}