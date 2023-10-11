#include<iostream>
using namespace std;
#include<vector>

struct Node
{
    int val;
    vector<Node*>neighbors;
};

class Solution
{
    public:
    void DFS(Node *copy,Node *original,vector<Node*>&visi)
    {
        if(!visi[copy->val])
        cout<<copy->val<<" ";

        visi[copy->val]=copy;

        for(Node *i:original->neighbors)
        {
            if(!visi[i->val])
            {
                Node *temp=new Node;
                temp->val=i->val;
                copy->neighbors.push_back(temp);
                DFS(temp,i,visi);
            }
            else
            {
                copy->neighbors.push_back(i);
            }
        }
    }

    Node *CloneGraph(Node *root)
    {
        if(root==NULL)
        return root;

        vector<Node*>visi(1000,NULL);
        Node *copy=new Node;
        copy->val=root->val;
        DFS(copy,root,visi);

    return copy;
    }
};


class Implementation //implementation using linked list
{
    public:
    Node *Representation(int v,vector<vector<int>>&prere)
    {
        vector<Node*>vec(v+1,NULL);
        Node *temp1,*temp2;
        for(int i=0;i<prere.size();i++)
        {
            if(vec[prere[i][0]]!=NULL)
            {
                temp1=vec[prere[i][0]];
            }
            else
            {
                temp1=new Node;
                temp1->val=prere[i][0];
                vec[prere[i][0]]=temp1;
            }

            if(vec[prere[i][1]]!=NULL)
            {
                Node *temp2=vec[prere[i][1]];
            }
            else
            {
                temp2=new Node;
                temp2->val=prere[i][1];
                vec[prere[i][1]]=temp2;
            }

            temp1->neighbors.push_back(temp2);
            temp2->neighbors.push_back(temp1);
        }
    return vec[1];
    }
};

int main()
{
    Implementation Graph;
    Solution M;
    vector<vector<int>>prere={{1,2},
                              {1,3},
                              {1,4},
                              {2,4},
                              {4,5},
                              {4,6},
                              {4,7},
                              };

    Node *root=Graph.Representation(7,prere);
    Node *p=M.CloneGraph(root);

return 0;
}