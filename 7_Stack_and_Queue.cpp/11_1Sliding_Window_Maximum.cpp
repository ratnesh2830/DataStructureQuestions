#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int> SlidingWindow(vector<int>&vec,int k)
    {
        int n=vec.size();
        vector<int>res;
        int ans=INT_MIN;
        for(int i=0;i<=n-k;i++)
        {
            int ans=0;
            for(int j=i;j<i+k;j++)
            {
                ans=max(vec[j],ans);
            }
        res.push_back(ans);
        }
    return res;

    }
};
int main()
{
    Solution M;
    vector<int>vec={4,0,-1,3,5,3,6,8};
    vector<int>res;
    res=M.SlidingWindow(vec,3);
    for(auto i:res)
    {
        cout<<i<<" ";
    }

return 0;
}