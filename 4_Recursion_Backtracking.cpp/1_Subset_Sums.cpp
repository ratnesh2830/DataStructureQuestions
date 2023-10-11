#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
    public:

    void function(int index,int sum,vector<int>&vec,int n,vector<int>&res)
    {
            if(index==n)
            {
                res.push_back(sum);
                return;
            }

            function(index+1,sum+vec[index],vec,n,res);
            function(index+1,sum,vec,n,res);
    }
    vector<int> Substsum(vector<int>&vec,int n,vector<int>&res)
    {
        int sum=0;
        int index=0;
        function(index,sum,vec,n,res);
        sort(res.begin(),res.end());
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{5,2,1};
    vector<int>res;
    M.Substsum(vec,3,res);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
return 0;
}