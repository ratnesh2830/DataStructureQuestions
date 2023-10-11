#include<iostream>
using namespace std;

class Solution
{
    public:
    int *A;
    int size;
    int front;
    int rear;
    int count;

    Solution()
    {
        count=0;
        size=1000;
        A=new int[1000];
        front=0;
        rear=0;
    }

    void push(int x)
    {
        if(count==size)
        cout<<"Queue is full"<<endl;

        A[rear%size]=x;
        rear++;
        count++;
    }

    int pop()
    {
        int x=-1;
        if(count==0)
        return x;

        x=A[front%size];
        A[front%size]=-1;
        front++;
        count--;
    
    return x;
    }

    int isempty()
    {
        if(count==0)
        return 1;
    
    return 0;
    }

    int isfull()
    {
        if(count==size)
        return 1;
    
    return 0;
    }

    void display()
    {
        if(count==0)
        {
            cout<<"queue is empty"<<endl;
        }

        int x=front;
        while(x<rear)
        {
            cout<<A[x%size]<<endl;
            x++;
        }
    }

    int topElement()
    {
        if(count==0)
        return -1;

        return A[front%size];
    }

    int peak(int posi)
    {
        if(front+posi-1>=rear)
        return -1;

    return A[(front+posi-1)%size];

    }

};

int main()
{
    Solution queue;
    queue.push(2);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(1);
    queue.pop();
    queue.pop();
    cout<<queue.peak(3);
        
return 0;
}