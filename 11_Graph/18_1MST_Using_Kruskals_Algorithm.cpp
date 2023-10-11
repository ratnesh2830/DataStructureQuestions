#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool comp(vector<int>a,vector<int>b)
{
    return a[2]<b[2];
}

class Solution
{
    private:
    int findpar(int vertex,vector<int>&parent)
    {
        if(parent[vertex]==vertex)
        return vertex;

        return parent[vertex]=findpar(parent[vertex],parent); //here we are doing path compressing making all the connected descendant nodes to the main root as their parent
    }

    void Union(int vertex1,int vertex2,vector<int>&parent,vector<int>&rank)
    {
        int u=findpar(vertex1,parent);
        int v=findpar(vertex2,parent);

        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if (rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else
        {
            parent[u]=v;
            rank[v]++;
        }
    }

    public:
    void KruskalsAlgorithm(int v,vector<vector<int>>&prerequisite)
    {
        vector<vector<int>>edge=prerequisite;
        sort(edge.begin(),edge.end(),comp);
        vector<int>parent(v+1);//one based indexing;
        for(int i=1;i<v+1;i++)
        {
            parent[i]=i;
        }
        vector<int>rank(v+1,0);
        
        int cost=0;
        vector<pair<int,int>>MST;
        for(auto it:edge)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(findpar(u,parent)!=findpar(v,parent))
            {
                cost+=w;
                MST.push_back({u,v});
                Union(u,v,parent,rank);
            }
        }

    cout<<cost<<endl;
    for(auto it:MST)
    {
        cout<<it.first<<"-->"<<it.second<<endl;
    }
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,4,1},
                                     {1,2,2},
                                     {1,5,4},
                                     {4,5,9},
                                     {4,3,5},
                                     {4,2,3},
                                     {2,3,3},
                                     {2,6,7},
                                     {3,6,8}};
    int Totalvertices=6;
    M.KruskalsAlgorithm(Totalvertices,prerequisite);
return 0;
}