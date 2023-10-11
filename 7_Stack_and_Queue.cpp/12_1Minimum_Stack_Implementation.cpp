#include<iostream>
using namespace std;
#include<utility>

class Solution
{
    public:

    pair<int,int>*A;
    int size;
    int top;
    int mini;
    
    Solution()
    {
        size=1000;
        top=-1;
        mini=INT_MAX;
        A=new pair<int,int>[size];
    }
    
    void push(int x)
    {
        if(top==size-1)
        cout<<"stack is full"<<endl;
        else
        {
            mini=min(mini,x);
            A[++top]={x,mini};
        }
    }

   int pop()
    {
        int x;
        if(top==-1)
         return -1;
        else
        {
            x=A[top--].first;
        }
    return x;
    }

    int topElement()
    {
        return A[top].first;
    }

    int minimumElement()
    {
        return A[top].second;
    }
};

int main()
{
    Solution M;
    M.push(2);
    M.push(-1);
    M.push(-5);
    M.push(7);
    M.push(10);

    cout<<endl<<M.topElement();
    cout<<endl<<M.minimumElement();
    M.pop();
    cout<<endl<<M.minimumElement();
    cout<<endl<<M.topElement();
return 0;
}