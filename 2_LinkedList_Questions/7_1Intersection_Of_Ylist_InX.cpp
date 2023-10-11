#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
struct Node
{
    int data;
    Node *next;
};
class Solution
{
    public:
    Node *Create(vector<int> &vec)
    {       
        Node *temp,*last;
        Node *head=new Node;
        head->data=vec[0];
        head->next=NULL;
        last=head;
        for(int i=1;i<vec.size();i++)
        {
            temp=new Node;
            temp->data=vec[i];
            temp->next=NULL;
            last->next=temp;
            last=temp;
        }
    return head;
    }
    Node *Intersection1(Node *HeadA,Node *HeadB)//brute force approach
    {
        if(HeadA==NULL || HeadB==NULL)
            return NULL;
        Node *q;
        while(HeadA!=NULL)
        {
                q=HeadB;
                while(q!=NULL)
                {
                    if(HeadA==q)
                        return HeadA;
                    else
                        q=q->next;
                }
            HeadA=HeadA->next;
        }
    return NULL;
    }

    Node *Intersection2(Node *HeadA,Node *HeadB)//optimized approach
    {
        if(HeadA==NULL || HeadB==NULL)
        return NULL;

        Node *p=HeadA,*q=HeadB;
        
        while(p!=q)
        {
            p= p==NULL?HeadB:p->next;
            q= q==NULL?HeadA:q->next;
        }
    return p;
    }

    Node *Intersection3(Node *HeadA,Node *HeadB)//using Unordered hashset
    {
        if(HeadA==NULL || HeadB==NULL)
        return NULL;
        unordered_set<Node*>set;
        while(HeadA!=NULL)
        {
            set.insert(HeadA);
            HeadA=HeadA->next;
        }
        while(HeadB!=NULL)
        {
            if(set.find(HeadB)!=set.end())
            {
                return HeadB;
            }
            else
            HeadB=HeadB->next;
        }
        
    return NULL;

    }
};
int main()
{
    Node *HeadA,*HeadB,*p;
    Solution M;
    vector<int>vec{4,1,8,4,5};
    vector<int>vec1{5,6,2,8,4,5};
    HeadA=M.Create(vec);
    HeadB=M.Create(vec1);
    p=M.Intersection3(HeadA,HeadB);
    cout<<p->data;
return 0;

}