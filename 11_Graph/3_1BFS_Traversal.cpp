#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    private:

    void BFStraversal(int vertex,vector<int>adj[],vector<int>&res,vector<int>&visi)
    {
        queue<int>q;
        q.push(vertex);
        visi[vertex]=1;

            while(!q.empty())
            {
                int v=q.front();
                q.pop();
                res.push_back(v);

                for(int i:adj[v])
                {
                    if(!visi[i])
                    {
                        visi[i]=1;
                        q.push(i);
                    }
                }
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

    vector<int>BFS(int v,vector<vector<int>>&prerequisite)
    {
        vector<int>res;
        if(prerequisite.size()==0)
        return res;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);

        vector<int>visi(v+1,0);

        for(int i=1;i<=v;i++)
        {
            if(!visi[i])
            BFStraversal(i,adj,res,visi);
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
    int TotalVertex=6;
    vector<int>res=M.BFS(TotalVertex,prerequisite);

    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}