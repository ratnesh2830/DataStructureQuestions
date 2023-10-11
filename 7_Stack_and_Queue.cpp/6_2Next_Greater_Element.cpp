#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:

    vector<int>NextGreaterElement(vector<int>&vec)
    {
        int n=vec.size();
        vector<int>res(n,-1);
        stack<int>stack;

        for(int i=2*n-1;i>=0;i--)
        {
            while(!stack.empty() && stack.top()<=vec[i%n])
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
    vector<int>vec={3,10,4,2,1,2,6,1,7,2,9};
    vector<int>res=M.NextGreaterElement(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}