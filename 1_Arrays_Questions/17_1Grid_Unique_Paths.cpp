//in this program the approach that we are doing is backtracking with the help of recursion to get all the possible unique paths paths
#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int CountPaths(int i,int j,int n,int m)
    {
        if(i==n-1 && j==m-1)
        return 1;

        if(i==n || j==m)
        return 0;

        return CountPaths(i+1,j,n,m)+CountPaths(i,j+1,n,m);
    }

    int UniquePaths(vector<vector<int>> &vec)
    {
        int n=vec.size();
        int m=vec[0].size();

        return CountPaths(0,0,n,m);
    }
};

int main()
{
    Solution M;
    vector<vector<int>> vec={{0,0,0,},
                             {0,0,0,}};
    cout<<M.UniquePaths(vec);
return 0;
}