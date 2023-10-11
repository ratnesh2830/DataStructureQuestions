//in this program the approach that we are doing is backtracking with the help of recursion but also we are using Dynamic Programming(Memoization) to decrease the time complexity
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int CountPaths(int i,int j,int n,int m,vector<vector<int>>&dp)
    {
        if(i==n-1 && j==m-1)
        return 1;

        if(i==n || j==m)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        return dp[i][j]=CountPaths(i+1,j,n,m,dp)+CountPaths(i,j+1,n,m,dp);
    }

    int UniquePaths(vector<vector<int>> &vec)
    {
        int n=vec.size();
        int m=vec[0].size();
        vector<vector<int>>dp{{-1,-1,-1},
                              {-1,-1,-1}};
        return CountPaths(0,0,n,m,dp);
    }
};

int main()
{
    Solution M;
    vector<vector<int>> vec={{0,0},
                             {0,0}};
    cout<<M.UniquePaths(vec);
return 0;
}