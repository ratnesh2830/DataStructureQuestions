#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
    public:

    void MaximumSum(vector<int>&A,vector<int>&B,int k)
    {
        vector<int>res;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                res.push_back(A[i]+B[j]);
            }
        }
    sort(res.begin(),res.end(),greater<int>());
    for(int i=0;i<k;i++)
    {
        cout<<res[i]<<endl;
    }
    }
};

int main()
{
    Solution M;
    vector<int>A={4,2,5,1};
    vector<int>B={8,0,3,5};
    M.MaximumSum(A,B,3);
return 0;
}