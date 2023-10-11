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
        }
    }

    void PrimsAlgorithm(int v,vector<vector<int>>&prerequisite)
    {
        vector<pair<int,int>>adj[v];
        Implementation(adj,prerequisite);
        vector<int>key(v,INT_MAX);
        vector<bool>MST(v,false);
        vector<int>parent(v,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        key[0]=0;//because we are going to start from this source node
        for(int i=0;i<v-1;i++)//because there will be only v-1 edges in our given MST graph
        {
            int u=pq.top().second;
            pq.pop();

            MST[u]=true;//means this vertex is now selected and now we have to traverse all of its edges and put the egde weight in key vector only if it is minimum than already 
                        //stored value and also the adjaent vertix is not a part of the MST(means we did not selected it yet)
            
            for(auto i:adj[u])
            {
                int v=i.first;
                int w=i.second;
                if(MST[v]==false && w<key[v])
                {   
                    key[v]=w;
                    parent[v]=u;
                    pq.push({w,v});

                }
            }
        }
    
    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<"--->"<<i<<endl;
    }
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{0,1,2},
                                     {0,3,6},
                                     {1,2,3},
                                     {1,4,5},
                                     {1,3,8},
                                     {2,4,7},};
    
    int Totalvertices=5;
    M.PrimsAlgorithm(Totalvertices,prerequisite);
return 0;
}