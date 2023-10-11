#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    private:
    bool DFScheckCycle(int vertex,vector<int>adj[],vector<int>&visi,vector<int>&dfsvisi)
    {
        visi[vertex]=1;
        dfsvisi[vertex]=1;

        for(int i:adj[vertex])
        {
            if(!visi[i])
            {
                if(DFScheckCycle(i,adj,visi,dfsvisi))
                return true;
            }
            else if(dfsvisi[i]==1)
            return true;
        }
    dfsvisi[vertex]=0;
    return false;
    }

    void Implementation(vector<int>adj[],vector<vector<int>>&prerequisite)
    {
        for(int i=0;i<prerequisite.size();i++)
        {
            int u,v;
            u=prerequisite[i][0];
            v=prerequisite[i][1];

            adj[u].push_back(v);
        }
    }

    public:
    bool DFScycleCheckInDirectedGraph(int v,vector<vector<int>>&prerequisite)
    {
        if(prerequisite.size()==0)
        return 0;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);
        vector<int>visi(v+1,0);
        vector<int>dfsvisi(v+1,0);

        for(int i=1;i<=v;i++)
        {
            if(!visi[i])
            {
                if(DFScheckCycle(i,adj,visi,dfsvisi))
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
                              {2,3},
                              {3,4},
                              {3,6},
                              {4,5},
                              {6,5},
                              {7,2},
                              {7,8},
                              {8,9},
                              };
    int TotalVertex=9;
    cout<<M.DFScycleCheckInDirectedGraph(TotalVertex,prerequisite);
return 0;
}