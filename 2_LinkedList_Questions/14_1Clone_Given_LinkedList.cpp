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

    Node *CloneList(Node *head)
    {
      if(head==NULL)
           return head;
        
        Node *p=head;
        Node *front,*t;
        while(p!=NULL)
        {
            front=p->next;
            t=new Node(p->val);
            p->next=t;
            t->next=front;
            p=front;
        }
     p=head;
        while(p!=NULL)
        {
            front=p->next->next;
            if(p->random==NULL)
            {
                p->next->random=NULL;
                p=front;
            }
            else
            {
                p->next->random=p->random->next;
                p=front;
            }
        }
    Node *headnew=new Node(0);
    headnew->next=head->next;
    t=headnew->next;
    p=head;
        while(p!=NULL)
        {
            front=p->next->next;
            p->next=front;
            t->next=front==NULL?NULL:front->next;
            p=front;
            t=t->next;
        }
    return headnew->next;
    }

};
