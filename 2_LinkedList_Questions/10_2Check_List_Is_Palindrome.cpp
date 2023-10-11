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

    bool PalindromeCheck(Node *head)
    {
        if(head==NULL || head->next==NULL)
        return true;

        Node *slow=head;
        Node *fast=head;

        //finding the first middle of the list if it is even or normal middle if it list is Odd
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *q=NULL,*p=slow->next,*t=NULL;
        while(p!=NULL)
        {
            t=p->next;
            p->next=q;
            q=p;
            p=t;
        }
    slow->next=q;
    slow=slow->next;
    fast=head;
    while(slow!=NULL)
    {
        if(fast->data!=slow->data)
        return false;
        else
        {
            slow=slow->next;
            fast=fast->next;
        }
    }

    return true;
    }
};
int main()
{
    Solution M;
    Node *head;
    vector<int>vec{1,2,3,3,2,1};
    head=M.Create(vec,head);
    cout<<M.PalindromeCheck(head);
return 0;
}