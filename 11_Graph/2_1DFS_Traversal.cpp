#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    private:
    
    void DFStraversal(int vertex,vector<int>adj[],vector<int>&res,vector<int>&visi)
    {
        visi[vertex]=1;
        res.push_back(vertex);

        for(int i:adj[vertex])
        {
            if(!visi[i])
            DFStraversal(i,adj,res,visi);
        }
    }
    void Implementation(vector<int>adj[],vector<vector<int>>&prerequisite)
    {
        for(int i=0;i<prerequisite.size();i++)
        {
            int u,v;
            u=prerequisite[i][0];
            v=prerequisite[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    public:
    vector<int> DFS(int v,vector<vector<int>>&prerequisite)
    {
        vector<int>res;

        if(prerequisite.size()==0)
        return res;

        vector<int>adj[v+1];//for 1 based indexing
        Implementation(adj,prerequisite);

        vector<int>visi(v+1,0);
        for(int i=1;i<=v;i++)
        {
            if(!visi[i])
            DFStraversal(i,adj,res,visi);
        }
    return res;
    }
};
int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,2},
                              {1,3},
                              {1,4},
                              {2,4},
                              {4,5},
                              {4,6},
                                    };
    int TotalVertex=7;
    vector<int>res=M.DFS(TotalVertex,prerequisite);

    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}