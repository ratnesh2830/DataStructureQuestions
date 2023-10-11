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

    Node *AddInList(Node *l1,Node *l2)
    {
        int num1=0,num2=0,sum=0;
        int i=1;
        
        while(l1!=NULL)
        {
            num1=num1+(i*l1->data);
            l1=l1->next;
            i=i*10;
        }
        i=1;
        while(l2!=NULL)
        {
            num2=num2+(i*l2->data);
            l2=l2->next;
            i=i*10;
        }

        sum=num1+num2;
        Node *l3,*last,*temp;
        l3=new Node;
        l3->data=0;
        l3->next=NULL;
        last=l3;

        while(sum>0)
        {
            temp=new Node;
            temp->data=sum%10;
            temp->next=NULL;
            last->next=temp;
            last=temp;
            sum=sum/10;         
       }
    
    return l3->next;

    }

};
int main()
{   
    Node *l1=NULL,*l2=NULL,*l3=NULL,*p;
    vector<int> vec1{5,6,7,9};
    vector<int> vec2{2,4,3};
    Solution M;
    l1=M.Create(vec1);
    l2=M.Create(vec2);
    l3=M.AddInList(l1,l2);
    p=l3;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;
}
