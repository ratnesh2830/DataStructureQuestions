#include<iostream>
using namespace std;
#include<queue>

class Solution
{
    public:
    queue<int>q1,q2;

    void push(int x)
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
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

    cout<<M.top()<<endl;
    M.pop();
    cout<<M.top();
return 0;

}