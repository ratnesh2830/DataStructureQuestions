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

    Node *LoopNode(Node *head)
    {
        if(head==NULL)
        return head;
        unordered_set<Node *>set;

        while(head!=NULL)
        {
            if(set.find(head)!=set.end())
            {
                return head;
            }
            else
            {
            set.insert(head);
            head=head->next;
            }
        }
    return head;
    }

    Node *  LoopNode(Node *head)
    {
        if(head==NULL)
        return head;

        Node* slow=head;
        Node* fast=head;
        do
        {
            slow=slow->next;
            fast=fast->next;
            fast=fast==NULL?NULL:fast->next;
        } while (slow!=fast && fast!=NULL);
        if(fast==NULL)
        return NULL;

        fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
    return slow;
    }
};
