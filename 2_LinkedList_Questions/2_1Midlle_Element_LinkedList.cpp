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

    Node *Middle(Node *head)
    {
        if(head==NULL)
        return head;

         Node *p=head;
         int count=0;
         while(p!=NULL)
          {
              count++;
              p=p->next;
           }
          int N=count/2;
          int i=0;
          p=head;
           while(i<N)
           {
               p=p->next;
               i++;
           } 

    return p;
     }
};

int main()
{
    Solution M;
    Node *head=NULL;
    vector<int>vec{1,2,3,4,5};
    head=M.Create(vec);
    Node *Mid=NULL;
    Mid=M.Middle(head);
    cout<<Mid->data;
    
return 0;
}
