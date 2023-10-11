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

    Node *Merge(Node *l1,Node *l2)
    {
        Node *head,*temp;

        if(l1->data<=l2->data)
        head=l1;
        else
        {
        head=l2;
        swap(l1,l2);
        }

        while(l1!=NULL && l2!=NULL)
        {
            while(l1!=NULL && l1->data<=l2->data)
            {
                temp=l1;
                l1=l1->next;
            }
        temp->next=l2;
        swap(l1,l2);
        }
    return head;
    }
    
    Node *Flattening(Node *head)
    {
        if(head==NULL || head->next==NULL)
        return head;

        head->next=Flattening(head->next);
        head=Merge(head,head->next);
        head->next=NULL;
    return head;
    }

};