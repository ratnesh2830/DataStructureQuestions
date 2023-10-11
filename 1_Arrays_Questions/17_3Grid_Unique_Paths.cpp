#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    double UniquePaths(vector<vector<int>> &vec)
    {
        int n=vec.size();
        int m=vec[0].size();
        int N=m+n-2; //total directions that need to take to reach the destination

        double res=1;
        int r=m-1;
        for(int i=1;i<=r;i++)
        {
            res=res*(N-r+i)/(i*1.0);
        }
    return res;

    }

};

int main()
{
    Solution M;
    vector<vector<int>>vec{{0,0,0,},
                           {0,0,0},
                           {0,0,0}};
    cout<<M.UniquePaths(vec);
return 0;
}
