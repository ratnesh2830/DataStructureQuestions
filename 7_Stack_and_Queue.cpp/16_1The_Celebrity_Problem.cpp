#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    int CelebrityProblem(vector<vector<int>>&vec)
    {
        int n=vec.size();
        int m=vec[0].size();
        int x=0;
        int row;
        for(int i=0;i<n;i++)
        {
            x=0;
            for(int j=0;j<m;j++)
            {
                if(vec[i][j]==1)
                {
                    x=1;
                    break;
                }
            }
        if(x==0)
        {
        row=i;
        break;
        }
        }

    if(x==1)
    return -1;

    for(int i=0;i<n;i++)
    {
        if(i==row)
        continue;
        if(vec[i][row]==0)
        return -1;
    }
    return row;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>vec={{0, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 1, 0, 0},
                            {0, 1, 0, 0},};
    cout<<M.CelebrityProblem(vec);
return 0;
}