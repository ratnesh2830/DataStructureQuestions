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
    vector<int>Inordertraversal1(Node *p)
    {
        static vector<int>res;
        if(p!=NULL)
        {
            Inordertraversal1(p->leftchild);
            res.push_back(p->data);
            Inordertraversal1(p->rightchild);
        }
    return res;
    }

    vector<int> Inordertraversal(Node *p)
    {
        vector<int>res;
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
                {
                    break;
                }
                p=st.top();
                st.pop();
                res.push_back(p->data);
                p=p->rightchild;
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
    vector<int>res=M.Inordertraversal1(bt.root);
    for(auto i:res)
    {
        cout<<i<<" ";
    }


return 0;
}