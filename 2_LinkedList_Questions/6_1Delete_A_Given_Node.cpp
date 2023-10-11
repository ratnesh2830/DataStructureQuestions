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

    void DeleteGivenNode(Node *p)
    {
        Node *q;
        q=p->next;    
        p->data=p->next->data;
        p->next=p->next->next;
        delete(q);
        
       
    }
};

int main()
{
    Node *head,*q;
    vector<int> vec{1,2,3,4,5};
    Solution M;
    head=M.Create(vec);
    q=head->next->next->next;
    M.DeleteGivenNode(q);
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;
}