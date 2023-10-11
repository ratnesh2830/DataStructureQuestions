#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    private:
    bool BFScycleCheck(int vertex,vector<int>adj[],vector<int>&visi)
    {
        queue<pair<int,int>>q;
        q.push({vertex,-1});
        visi[vertex]=1;

        while(!q.empty())
        {
            int v=q.front().first;
            int par=q.front().second;
            q.pop();
            
            for(auto i:adj[v])
            {
                if(!visi[i])
                {
                    visi[i]=1;
                    q.push({i,v});
                }
                else if(i!=par)
                {
                return true;
                }
            }
        }
    return false;
    }

    void implementation(vector<int>adj[],vector<vector<int>>&prerequisite)
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
    bool BFScycleUndirectedGraph(int v,vector<vector<int>>&prerequisite)
    {
        if(prerequisite.size()==0)
        return false;

        vector<int>adj[v+1];
        implementation(adj,prerequisite);
        vector<int>visi(v+1,0);

        for(int i=1;i<=v;i++)
        {
            if(!visi[i])
            {
                if(BFScycleCheck(i,adj,visi))
                return true;
            }
        }
    return false;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,2},
                              {1,3},
                              {2,4},
                              {4,5},
                              {5,6},
                              {5,7},
                              
                              };
    int TotalVertex=7;
    cout<<M.BFScycleUndirectedGraph(TotalVertex,prerequisite);
return 0;
}