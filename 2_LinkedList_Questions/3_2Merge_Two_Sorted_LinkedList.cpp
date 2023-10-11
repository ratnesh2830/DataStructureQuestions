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

    Node *MergeLinkList(Node *l1,Node *l2)
    {
        Node *head=NULL;
        if(l1==NULL && l2==NULL)
            return head;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        Node *temp=NULL;
        if(l1->data<=l2->data)
        {
            head=l1;
        }
        else
        {
            head=l2;
            swap(l1,l2);
        }
        while(l1!=NULL && l2!=NULL)
        {
            while(l1!=NULL && l1->data <= l2->data)
            {
                temp=l1;
                l1=l1->next;
            }
        temp->next=l2;
        swap(l1,l2);
        }
    return head;

    }
};

int main()
{
    Node *First,*Second,*Third;
    vector<int> vec1{3,7,10};
    vector<int> vec2{1,2,5,8,10};
    Solution M;
    First=M.Create(vec1);
    Second=M.Create(vec2);
    Third=M.MergeLinkList(First,Second);
    Node *p=Third;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
return 0;
}