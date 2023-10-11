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

        Node *q,*p;
        p=head;
        int count=0;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
    p=head;
    int N=count-n;
    if(N!=0)
    {
        for(int i=0;i<N;i++)
        {
            q=p;
            p=p->next;
        }
    q->next=p->next;
    delete(p);
    }
    else
    {   
        head=p->next;
        delete(p);
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
