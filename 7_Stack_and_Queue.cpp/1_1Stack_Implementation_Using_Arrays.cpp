#include<iostream>
using namespace std;

class Solution
{
    public:
    int *A;
    int top;
    int n;

    Solution()  //using contructor 
    {
        top=-1;
        n=1000;
        A=new int[n];
    }
    void push(int x)
    {
        if(top==n-1)
        cout<<"stack overflow"<<endl;

        else
        A[++top]=x;
    }

    int pop()
    {
        int x=-1;

        if(top==-1)
        return x;
        else
        x=A[top--];

    return x;
    }

    int TopElement()
    {
        return A[top];
    }

    int Size()
    {
        return top+1;
    }

    int Peak(int posi)  //to look for a element in a particular position 
    {
        int x=-1;
        if(top-posi+1<0)
        return x;

        else
        x=A[top-posi+1];
    
    return x;
    }

    void display()
    {
        int x=top;
        while(x>-1)
        {
            cout<<A[x--]<<" ";
        }
    }

    int isempty()
    {
        if(top==-1)
        return 1;

    return 0;
    }

    int isFull()
    {
        if(top==n-1)
        return 1;
    
    return 0;
    }
};

int main()
{
    Solution stack;

    stack.push(2);
    stack.push(6);
    stack.push(1);
    stack.push(11);
    stack.push(29);
    stack.display();
    cout<<stack.pop();
    cout<<endl<<stack.pop();
    cout<<endl<<stack.TopElement()<<endl;;
//cout<<stack.Peak(2);
return 0;

}