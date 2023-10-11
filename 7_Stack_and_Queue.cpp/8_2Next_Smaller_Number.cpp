#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution
{
    public:

    vector<int>NextSmallerElement(vector<int>&vec)
    {
        int n=vec.size();
        stack<int>stack;
        vector<int>res(n,-1);

        for(int i=2*n-1;i>=0;i--)
        {
            while(!stack.empty() && stack.top()>=vec[i%n])
            {
                stack.pop();
            }   
            if(i<n)
            {
                if(!stack.empty())
                {
                    res[i]=stack.top();
                }
            }
            stack.push(vec[i%n]);
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec={1,2,3,4,5,6,7};
    vector<int>res=M.NextSmallerElement(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}