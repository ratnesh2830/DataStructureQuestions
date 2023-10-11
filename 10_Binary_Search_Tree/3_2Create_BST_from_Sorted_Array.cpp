#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


struct Node
{
    Node *left;
    int value;
    Node *right;
};

class Solution
{
    public:
    Node *BT(vector<int>&vec,int start,int end)
    {
        if(start > end)
        return NULL ;

        int mid=(start+end)/2;
        Node *temp=new Node;
        temp->value=vec[mid];
        temp->left=temp->right=NULL;

        temp->left=BT(vec,start,mid-1);
        temp->right=BT(vec,mid+1,end);
    
    return temp;
    }

    Node *Construct(vector<int>&vec)
    {
        return BT(vec,0,vec.size()-1);
    }

    void inorder(Node *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->value<<" ";
            inorder(root->right);
        }
    }
};

int main()
{
    Solution M;
    vector<int>vec={2,4,6,8,10,12,14};
    Node *root=M.Construct(vec);
    M.inorder(root);

return 0;

}