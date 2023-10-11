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

    Node *Rotate(Node *head,int k)
    {
        if(head==NULL || head->next==NULL)
        return head;

        Node *p=head;
        int count=1;
        while(p->next!=NULL)
        {
            count++;
            p=p->next;
        }
        int N=count-(k%count);
        Node *t=head,*r,*q=head;

        while(N>1)
        {
            t=t->next;
            N--;
        }
    r=t->next;
    t->next=p->next;
    p->next=q;
    head=r;

    return head;
    }

};
int main()
{
    Node *head;
    Solution M;
    vector<int> vec{1,2};
    head=M.Create(vec,head);
    head=M.Rotate(head,11);
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;
}