#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    private:
    void BFS(int row,int col,vector<vector<int>>&visi,vector<vector<int>>&grid)
    {
        visi[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});

        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int deltar=-1;deltar<=1;deltar++)
            {
                for(int deltac=-1;deltac<=1;deltac++)
                {
                    int newrow=row+deltar;
                    int newcol=col+deltac;
                if(newrow<n && newrow>=0 && newcol<m && newcol>=0 && !visi[newrow][newcol] && grid[newrow][newcol]==1)
                {
                    visi[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
                }
            }
        }
    }

    public:
    int NumberOfIslands(vector<vector<int>>&grid)
    {
        if(grid.size()==0)
        return 0;

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visi(n,vector<int>(m,0));

        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visi[i][j] && grid[i][j]==1)
                {
                    BFS(i,j,visi,grid);
                    count++;
                }
            }
        }
    return count;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>grid={{0,1,1,0},
                             {0,0,1,0},
                             {1,0,1,0},
                             {0,0,0,0},
                             {1,1,0,1},};
    cout<<M.NumberOfIslands(grid);
return 0;
}