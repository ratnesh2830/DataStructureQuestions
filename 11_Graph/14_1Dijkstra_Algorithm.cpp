#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    public:
    void Implementation(vector<pair<int,int>>adj[],vector<vector<int>>&prerequisite)
    {
        for(int i=0;i<prerequisite.size();i++)
        {
            int u,v,w;
            u=prerequisite[i][0];
            v=prerequisite[i][1];
            w=prerequisite[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }
    vector<int>DisjkstraAlgorithm(int v,int source,vector<vector<int>>&prerequisite)
    {
        vector<pair<int,int>>adj[v+1];
        Implementation(adj,prerequisite);
        vector<int>dist(v+1,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[source]=0;
        pq.push({0,source});

        while(!pq.empty())
        {
            int predist=pq.top().first;
            int v=pq.top().second;
            pq.pop();

            for(auto i:adj[v])
            {
                int next=i.first;
                int nextdist=i.second;
                
                if(dist[next]>predist+nextdist)
                {
                    dist[next]=predist+nextdist;
                    pq.push({dist[next],next});
                }
            }
        }
    return dist;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,2,5},
                              {1,4,8},
                              {2,3,2},
                              {2,4,9},
                              {3,4,6},
                                  };
    int TotalVertex=4;
    int source=1;
    vector<int>res=M.DisjkstraAlgorithm(TotalVertex,source,prerequisite);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
