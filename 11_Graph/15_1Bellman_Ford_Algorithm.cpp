#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    void Implementation(vector<pair<int,int>>adj[],vector<vector<int>>&prerquisite)
    {
        for(int i=0;i<prerquisite.size();i++)
        {
            int u,v,w;
            u=prerquisite[i][0];
            v=prerquisite[i][1];
            w=prerquisite[i][2];

            adj[u].push_back({v,w});
        }
    }

    vector<int> BellmanForAlgorithm(int v,int source,vector<vector<int>>&prerquisite)
    {
        vector<pair<int,int>>adj[v];
        Implementation(adj,prerquisite);
        vector<int> dist(v,INT_MAX-1000);
        dist[source]=0;

        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<v;j++)//vertices are starting from 0
            {
                for(auto k:adj[j])
                {
                    int u=j;
                    int v=k.first;
                    int w=k.second;
                if(dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                }
                }
            }
        }
        
        //doing one more time and if any value changes to lesser than it means there is a negative cycle present in the directed graph
        int flag=0;
        for(int j=0;j<v;j++)//vertices are starting from 0
            {
                for(auto i:adj[j])
                {
                    int u=j;
                    int v=i.first;
                    int w=i.second;
                if(dist[u]+w<dist[v])
                {
                    flag=1;
                    break;
                }
                }
            if(flag==1)
            break;
            }
    if(!flag)
    return dist;

    dist.clear();
    return dist;
        
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{0,1,5},
                              {1,5,-3},
                              {1,2,-2},
                              {5,3,1},
                              {3,2,6},
                              {3,4,-2},
                              {2,4,3},
                                  };
    int TotalVertex=6;
    int source=0;
    vector<int>res=M.BellmanForAlgorithm(TotalVertex,source,prerequisite);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}