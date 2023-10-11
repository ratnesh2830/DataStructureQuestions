#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>

struct Node
{
    Node*leftchild;
    int data;
    Node*rightchild;
};

class Solution
{
    public:
  vector<vector<int>>VerticalOrderTraversal(Node *p)
  {
    vector<vector<int>>res;
    if(p==NULL)
    return res;
    queue<pair<Node*,pair<int,int>>>q;
    map<int,map<int,multiset<int>>>map; //in multiset same elements are allowed
    q.push({p,{0,0}});
    while(!q.empty())
    {
        p=q.front().first;
        int x=q.front().second.first; //verticle
        int y=q.front().second.second;//level
        map[x][y].insert(p->data); //we are using insert because we are using set and to insert in set we use insert
        q.pop();
        if(p->leftchild!=NULL)
        {
            q.push({p->leftchild,{x-1,y+1}});
        }
        if(p->rightchild!=NULL)
        {
            q.push({p->rightchild,{x+1,y+1}});
        }
    }
    for(auto i:map)
    {
        vector<int>vec;
        for(auto j:i.second)
        {
            vec.insert(vec.end(),j.second.begin(),j.second.end());
        }
    res.push_back(vec);
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
    vector<vector<int>>res;
    res=M.VerticalOrderTraversal(bt.root);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
    cout<<endl;
    }

return 0;
}