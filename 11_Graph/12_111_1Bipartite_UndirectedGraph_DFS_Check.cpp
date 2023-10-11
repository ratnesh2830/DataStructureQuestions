#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    private:
    bool DFS(int vertex,vector<int>adj[],vector<int>&col)
    {
        if(col[vertex]==-1) //initial starting vertex initialization of a component of a graph
         col[vertex]=1;

         for(auto i:adj[vertex])
         {
            if(col[i]==-1)
            {
                col[i]=1-col[vertex];
                if(!DFS(i,adj,col))
                return false;
            }
            else if(col[i]==col[vertex])
            return false;
         }
        return true;
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
    bool BipartiteCheckDFS(int v,vector<vector<int>>&prerequisite)
    {
        if(prerequisite.size()==0)
        return true;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);
        vector<int>col(v+1,-1);

        for(int i=1;i<=v;i++)
        {
            if(col[i]==-1)
            {
                if(!DFS(i,adj,col))
                return false;
            }
        }
    return true;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,2},
                              {2,3},
                              {2,4},
                              {3,5},
                              {4,6},
                              {5,7},
                              {6,7},
                              {7,8},
                                  };
    int TotalVertex=8;
    cout<<M.BipartiteCheckDFS(TotalVertex,prerequisite);

return 0;
}