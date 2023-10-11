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

    Node *RemoveNthfromend(Node *head,int n)
    {
        if(head==NULL)
        return NULL;

        Node *fast=head,*slow=head,*q=NULL;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }

        while(fast!=NULL)
        {
            q=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(q!=NULL)
        {
            q->next=slow->next;
            delete(slow);
        }
        else
        {
            head=slow->next;
            delete(slow);
        }
    return head;
    }
};
int main()
{
    Node *head=NULL,*p;
    Solution M;
    vector<int> vec{1,2,3,4,5,6};
    head=M.Create(vec);
    head=M.RemoveNthfromend(head,6);
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;

}
