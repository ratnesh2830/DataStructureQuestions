#include<iostream>
using namespace std;
#include<queue>

class Solution
{
    public:
    queue<int>q1;
    
    void push(int x)
    {
        q1.push(x);

        int n=q1.size()-1;

        while(n!=0)
        {
            q1.push(q1.front());
            q1.pop();
            n--;
        }
    }

    void pop()
    {
        q1.pop();
    }

    int top()
    {
        return q1.front();
    }
};

int main()
{
    Solution M;
    M.push(2);
    M.push(3);
    M.push(4);
    M.push(5);
    cout<<endl<<M.top();
    M.pop();
    cout<<endl<<M.top();
return 0;
}