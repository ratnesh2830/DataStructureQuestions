#include<iostream>
using namespace std;
#include<utility>

class Solution
{
    public:

    int *A;
    int size;
    int top;
    int mini;
    
    Solution()
    {
        size=1000;
        top=-1;
        mini=INT_MAX;
        A=new int[size];
    }
    
    void push(int x)
    {
        if(top==size-1)
        cout<<"stack is full"<<endl;

        else if(top==-1)
            {
                mini=x;
                A[++top]=x;
            }
        else if(x<A[top])
        {
            int value=(2*x)-mini;
            mini=x;
            A[++top]=value;
        }
        else
        {
            A[++top]=x;
        }
    }

    int pop()
    {
        int x;
        if(top==-1)
        return -1;

        else if(A[top]<mini)
        {
            x=A[top];
            mini=2*mini-A[top--];
        }
        else
        {
            x=A[top--];
        }
    return x;
    }

    int topelement()
    {
        if(A[top]<mini)
        return mini;
    
    return A[top];
    }

    int miniElement()
    {
        return mini;
    }

};

int main()
{
    Solution M;
    M.push(-1);
    M.push(3);
    M.push(-4);
    M.push(6);
    M.push(10);

    cout<<M.miniElement()<<endl;
    M.pop();
    cout<<M.topelement()<<endl;
    cout<<M.miniElement()<<endl;
    M.pop();
    cout<<M.miniElement()<<endl;
    M.pop();
    cout<<M.miniElement()<<endl;
return 0;
}
