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
    Node *Create(vector<int> &vec,Node *head)
    {       
        Node *temp,*last;
        head=new Node;
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

    Node *ReverseinKSize(Node *head,int k)
    {
        if(head==NULL || k==1)
        return NULL;
        Node *p=head;
        int count=0;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        int N=count/k;
        Node *headnew=new Node;
        headnew->data=0;
        headnew->next=head;
        Node *q=headnew;
        Node *t;
        while(N!=0)
        {
            p=q->next;
            t=p->next;
                for(int i=1;k-i>0;i++)
                {
                    p->next=t->next;
                    t->next=q->next;
                    q->next=t;
                    t=p->next;
                }
            q=p;
            N--;
        }
    return headnew->next;
    }

};
int main()
{
    Solution M;
    Node *head;
    vector<int>vec{1,2,3,4,5,6,7,8};
    int k=3;
    head=M.Create(vec,head);
    head=M.ReverseinKSize(head,k);
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;
}