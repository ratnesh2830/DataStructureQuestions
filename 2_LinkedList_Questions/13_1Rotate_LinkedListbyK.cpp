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

        Node *q=head,*p=head,*t;
        while(k!=0)
        {
            q=head;
            while(p->next!=NULL)
            {
                t=p;
                p=p->next;
            }
        t->next=p->next;
        p->next=q;
        head=p;
        k--;
        }
    return head;
    }
};
int main()
{
    Node *head;
    Solution M;
    vector<int> vec{1,2,3,4,5};
    head=M.Create(vec,head);
    head=M.Rotate(head,3);
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;
}