#include<iostream>
using namespace std;
#include<vector>


class Solution
{
    public:
    int floydWarshall(int n,vector<vector<int>> &edges) 
{
    vector<vector<int>>dist(n+1,vector<int>(n+1,INT_MAX));   
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            dist[i][j]=0;}
   }
    
    for(int i=0;i<edges.size();i++)
    {
        int u,v,w;
        u=edges[i][0];
        v=edges[i][1];
        w=edges[i][2];
        dist[u][v]=w;
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                else if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

for(int i=0;i<=n;i++)
{
    for(int j=0;j<=n;j++)
    {
        cout<<dist[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;
   return dist[1][3];

 }
};

int main()
{
    Solution M;
    vector<vector<int>>edges={{1,2,2},
                              {1,3,2},
                              {2,3,-1},};
    cout<<M.floydWarshall(3,edges);
return 0;
}