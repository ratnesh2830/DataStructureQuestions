#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>


struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};

class Solution
{
    public:

    vector<int>leftview1(Node *p,int level)
    {
        static vector<int>res;
        if(p==NULL)
        return res;
        if(level==res.size())
        {
            res.push_back(p->data);
        }

        
        
            leftview1(p->leftchild,level+1);
            leftview1(p->rightchild,level+1);
        
    return res;
    }

    vector<int>leftview(Node *p) //using level order traversal
    {   
        vector<int>res;
        if(p==NULL)
        return res;
        queue<Node*>q;
        q.push(p);
        while(!q.empty())
        {   
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                p=q.front();
                if(i==1)
                res.push_back(p->data);

                if(p->leftchild!=NULL)
                q.push(p->leftchild);

                if(p->rightchild!=NULL)
                q.push(p->rightchild);
            
            q.pop();
            }
        }
    return res;
    }

    vector<int>rightview1(Node *p,int level)
    {
        static vector<int>res;
        if(p==NULL)
        return res;
        if(level==res.size())
        {
            res.push_back(p->data);
        }

        if(p!=NULL)
        {
            rightview1(p->rightchild,level+1);
            rightview1(p->leftchild,level+1);
        }
    return res;
    }

    vector<int>rightview(Node *p) //using level order traversal
    {   
        vector<int>res;
        if(p==NULL)
        return res;
        queue<Node*>q;
        q.push(p);
        while(!q.empty())
        {   
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                p=q.front();
                if(i==1)
                res.push_back(p->data);

                if(p->rightchild!=NULL)
                q.push(p->rightchild);

                if(p->leftchild!=NULL)
                q.push(p->leftchild);
            
            q.pop();
            }
        }
    return res;
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
    vector<int>res=M.leftview1(bt.root,0);
    for(auto i:res)
    {
        cout<<i<<" ";
    }


return 0;
}