
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

    Node* Reverse(Node* head) //reversing a linked list using iterative method
    {
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
            return head;
        }
    Node *q=NULL,*p=head,*t;
        while(p!=NULL)
         {
             t=p->next;
             p->next=q;
             q=p;
             p=t;
         }

    head=q;
    return head;

    }

    Node *ReverseR(Node *q,Node *p) //reversing a linked list using recursion
    {
        static Node *Head;
        if(p!=NULL)
        {
            ReverseR(p,p->next);
            p->next=q;
        }
        else
        {
            Head=q;
        }
    return Head;
    }

    
};

int main()
{
    Solution M;
    Node *head=NULL;
    Node *q=NULL;
    vector<int>vec{1,2,3,4,5};
    head=M.Create(vec,head);
    head=M.ReverseR(q,head);
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    

return 0;
}