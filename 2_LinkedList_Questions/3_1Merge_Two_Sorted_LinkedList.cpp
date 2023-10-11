#include<iostream>
using namespace std;
#include<vector>

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

    Node * MergeLinkList(Node *first,Node *second)
    {
        Node *p,*t,*q,*head;
        p=first;
        q=second;
        if(first==NULL || second==NULL)
        return head;

        head=new Node;
        head->data=0;
        head->next=NULL;
        Node* last=head;

        while(p!=NULL && q!=NULL)
        {
            if(p->data<= q->data)
                {
                    t=new Node;
                    t->data=p->data;
                    t->next=NULL;
                    last->next=t;
                    last=t;
                    p=p->next;
                }
            else
            {
                    t=new Node;
                    t->data=q->data;
                    t->next=NULL;
                    last->next=t;
                    last=t;
                    q=q->next;
            }
        }
while(p!=NULL)
{
    t=new Node;
    t->data=p->data;
    t->next=NULL;
    last->next=t;
    last=t;
    p=p->next;
}
while(q!=NULL)
{
    t=new Node;
    t->data=q->data;
    t->next=NULL;
    last->next=t;
    last=t;
    q=q->next;
}

return head->next;

    }
};

int main()
{
    Node *First,*Second,*Third;
    vector<int> vec1{3,7,10};
    vector<int> vec2{1,2,5,8,10};
    Solution M;
    First=M.Create(vec1);
    Second=M.Create(vec2);
    Third=M.MergeLinkList(First,Second);
    Node *p=Third;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
return 0;
}
