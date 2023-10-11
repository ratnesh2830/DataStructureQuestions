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
    bool DetectCycle(Node *head)//Using brute Force Approach USING HASHSET to store the address of each node
    {
        if(head==NULL)
        return false;
        unordered_set<Node*> set;

        while(head!=NULL)
        {
            if(set.find(head)!=set.end())
                return true;
            else
            {
            set.insert(head);
            head=head->next;
            }
        }
    return false;

    }

    bool DetectCycle(Node *head)
    {
        if(head==NULL)
        return false;

        Node *slow=head;
        Node *fast=head;

        do
        {
            slow=slow->next;
            fast=fast->next;
            fast=fast!=NULL?fast->next:NULL;
        } while(slow!=fast && fast!=NULL);
        if(fast==NULL)
        return false;

    return true;

    }
};