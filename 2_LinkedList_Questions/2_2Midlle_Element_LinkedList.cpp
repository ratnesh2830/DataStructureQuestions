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

    Node * Middle(Node *head)
    {
        if(head==NULL)
        return head;

        Node *slow,*fast;
        slow=fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
    return slow;
    }

};

int main()
{
    Node *head=NULL;
    Solution M;
    vector<int> vec{1,2,3,4,5,6,7};
    head=M.Create(vec);
    Node *Mid=NULL;
    Mid=M.Middle(head);
    cout<<Mid->data;
return 0;
}