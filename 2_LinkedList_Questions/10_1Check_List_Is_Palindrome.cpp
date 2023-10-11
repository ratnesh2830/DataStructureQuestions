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

        vector<int>vec;
        Node  *p=head;
        while(p!=NULL)
        {
            vec.push_back(p->data);
            p=p->next;
        }
        for(int i=0,j=vec.size()-1;i<j;i++,j--)
        {
            if(vec[i]!=vec[j])
            return false;
        }
    return true;
    }
};
int main()
{
    Solution M;
    Node *head;
    vector<int>vec{1,2,3,4,2,1};
    head=M.Create(vec,head);
    cout<<M.PalindromeCheck(head);
return 0;
}