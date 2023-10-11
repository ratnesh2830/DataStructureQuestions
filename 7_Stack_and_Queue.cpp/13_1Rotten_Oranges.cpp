#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
    public:

    int RottenOrange(vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>queue;
        vector<vector<int>>visi(n,vector<int>(m,0));
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    queue.push({{i,j},0});
                    visi[i][j]=2;
                }
                if(grid[i][j]==1)
                {
                    count++; //counting fresh oranges
                }
            }
        }

        int drow[4]={+1,0,0,-1};
        int dcol[4]={0,-1,+1,0};
        int cnt=0;
        int t=0;
        while(!queue.empty())
        {
            int row=queue.front().first.first;
            int col=queue.front().first.second;
            t=queue.front().second;
            queue.pop();

            for(int i=0;i<4;i++)
            {   
                int newrow=row;
                int newcol=col;
                newrow=row+drow[i];
                newcol=col+dcol[i];
                if(newrow<n && newcol>=0 && newcol<m && newrow>=0 && visi[newrow][newcol]!=2 && grid[newrow][newcol]==1)
                {
                    visi[newrow][newcol]=2;
                    queue.push({{newrow,newcol},t+1}); 
                    cnt++;
                }
            }
        }

        if(cnt!=count)
        return -1;

        return t;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>grid={{2,1,0},
                             {2,1,1},
                             {1,0,0},};
    cout<<M.RottenOrange(grid);
return 0;
}