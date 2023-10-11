#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<sstream>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};


class Solution
{
    public:

    string Serialization(Node *p) //here we are going to convert all the elements in the BT into string and seperate each element with , and for NULL childrens we use #
    {
        if(p==NULL)
        return "";

        string str;
        queue<Node *>q;
        q.push(p);
        while(!q.empty())
        {
            p=q.front();
            q.pop();

            if(p!=NULL)
            {
                q.push(p->leftchild);
                q.push(p->rightchild);
            }
            
            if(p==NULL)
            str+="#,";
            else
            str+=to_string(p->data)+',';

            
        }
    return str;
    }

    Node* Deserialozation(string data)
    {
        if(data.size() == 0) 
        return NULL; 

        stringstream s(data); 
        string str;
        getline(s, str, ',');
        Node *root = new Node;
        root->data=stoi(str);
        queue<Node*> q; 
        q.push(root); 

        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#")
            {
            temp->leftchild=NULL;
            }
            else
            {
            Node *left=new Node;
            left->data=stoi(str);
            temp->leftchild=left;
            q.push(left);
            }
            
            getline(s,str,',');
            if(str=="#")
            {
            temp->rightchild=NULL;
            }
            else
            {
                Node *right=new Node;
                right->data=stoi(str);
                temp->rightchild=right;
                q.push(right);
            }
        }
    
    return root;
    }

    void Inordertraversal1(Node *p)
    {
        if(p!=NULL)
        {
            Inordertraversal1(p->leftchild);
            cout<<p->data<<" ";
            Inordertraversal1(p->rightchild);
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
    string str=M.Serialization(bt.root);
    cout<<str<<endl;
    Node *p=M.Deserialozation(str);
    M.Inordertraversal1(p);

    
return 0;
}