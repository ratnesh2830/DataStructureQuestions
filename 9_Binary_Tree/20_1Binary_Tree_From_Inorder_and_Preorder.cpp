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

    Node * Construct(vector<int>&Inor,int instart,int inend,vector<int>&pre,int prestart,int preend,unordered_map<int,int>&map)
    {
        if(prestart>preend || instart>inend)
        return NULL;

        Node *root=new Node;
        root->data=pre[prestart];
        root->leftchild=root->rightchild=NULL;

        int inroot=map[pre[prestart]];
        int left=inroot-instart;

        root->leftchild=Construct(Inor,instart,inroot-1,pre,prestart+1,prestart+left,map);
        root->rightchild=Construct(Inor,inroot+1,inend,pre,prestart+left+1,preend,map);

        return root;

    }

    Node *ConstructBT(vector<int>&Inor,vector<int>&pre)
    {
        unordered_map<int,int>map;
        for(int i=0;i<Inor.size();i++)
        {
            map[Inor[i]]=i;
        }

        Node *root=Construct(Inor,0,Inor.size()-1,pre,0,pre.size()-1,map);
    
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
    vector<int>Inor={40,20,50,10,60,30};
    vector<int>pre={10,20,40,50,30,60};
    Node *root=M.ConstructBT(Inor,pre);
    M.inordertraversal(root);
    cout<<endl;
    M.preordertraversal(root);
return 0;
}