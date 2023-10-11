#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    private:
    
    bool DFScycleCheck(int v,int par,vector<int>adj[],vector<int>&visi)
    {
        
        visi[v]=1;

        for(auto i:adj[v])
        {
            if(!visi[i])
            {
                if(DFScycleCheck(i,v,adj,visi))
                return true;
            }
            else if(i!=par)
            return true;
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
    bool DFScycleChceckInUndirectedGraph(int v,vector<vector<int>>&prerequisite)
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
                if(DFScycleCheck(i,-1,adj,visi))
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
                              {3,4},
                              {3,6},
                              {2,5},
                              {5,7},
                              {6,7}
                              };
    int TotalVertex=7;
    cout<<M.DFScycleChceckInUndirectedGraph(TotalVertex,prerequisite);
return 0;
}