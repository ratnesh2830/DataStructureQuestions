#include"12BST.h"

class BSTiterator
{
    public:
    stack<Node*>st;
    bool reverse;

    BSTiterator(Node *p,bool isreverse)
    {
        reverse=isreverse;
        pushall(p);
    }

    bool hasnext()
    {
        if(st.empty()==true)
        return false;
    
    return true;
    }

    int next()
    {
        Node *p=st.top();
        st.pop();
        if(reverse==true)
        {
            pushall(p->leftchild);
        }
        else
        {
            pushall(p->rightchild);
        }
    return p->data;
    }

    private:
    
    void pushall(Node *p)
    {
        while(p!=NULL)
        {
            st.push(p);
            if(reverse==true)
            {
                p=p->rightchild;
            }
            else
            {
                p=p->leftchild;
            }
        }
    }
};


class Solution
{
    public:
    bool PairforGivenSumInBST(Node *p,int key)
    {
        if(p==NULL)
        return false;

        BSTiterator l(p,false);
        BSTiterator r(p,true);

        int i=l.next();
        int j=r.next();

        while(i<j)
        {
            if(i+j==key)
            return true;

            else if(i+j<key)
            {
                i=l.next();
            }
            else
            {
                j=r.next();
            }
        }
    return false;
    }
};


int main()
{
    BinarySearchTree bst;
    vector<int>vec={6,1,8,0,12,7,9,3,5};
    Node *root=NULL;
    root=bst.CreateBSTIterative(root,vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        bst.CreateBSTIterative(root,vec[i]);
    }
    
    Solution M;
    cout<<M.PairforGivenSumInBST(root,2);
    
return 0;
}