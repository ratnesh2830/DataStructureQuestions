#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    public:

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
    vector<int> TopologicalSortBFS(int v,vector<vector<int>>&prerequisite)
    {
        vector<int>res;
        if(prerequisite.size()==0)
        return res;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);

        vector<int>Indeg(v+1,0);
        for(int i=1;i<=v;i++)
        {
            for(auto j:adj[i])
            {
                Indeg[j]++;
            }
        }
        queue<int>q;
        for(int i=1;i<=v;i++)
        {
            if(Indeg[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int vertex=q.front();
            q.pop();
            res.push_back(vertex);
            for(auto i:adj[vertex])
            {
                Indeg[i]--;
                if(Indeg[i]==0)
                q.push(i);
            }
        }
    
    return res;
    }  
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,2},
                              {2,3},
                              {2,7},
                              {3,4},
                              {3,6},
                              {4,5},
                              {6,9},
                              {6,7},
                              {7,8},
                              {8,9},
                              
                              };
    int TotalVertex=9;
    vector<int>res=M.TopologicalSortBFS(TotalVertex,prerequisite);

    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}