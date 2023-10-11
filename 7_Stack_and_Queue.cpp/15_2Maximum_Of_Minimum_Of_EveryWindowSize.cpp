#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution
{
    public:
    vector<int>MaximumOfMinimum(vector<int>&vec)
    {
        int n=vec.size();
        deque<int>dq;
        vector<int>res;
        int ansmaxi=INT_MIN;
        int k=1;
        while(k<=n)
        {
            ansmaxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
                while(!dq.empty() && dq.front()==i-k)
                {
                 dq.pop_front();
                }

                while(!dq.empty() && vec[dq.back()]>vec[i])
                {
                 dq.pop_back();
                }

                dq.push_back(i);
                if(i>=k-1)
                {
                    ansmaxi=max(ansmaxi,vec[dq.front()]);
                }
            }
        res.push_back(ansmaxi);
        k++;
        }
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={10,20,30,50,10,70,30};
    vector<int>res=M.MaximumOfMinimum(vec);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}