#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    private:
    bool BFS(int vertex,vector<int>adj[],vector<int>&col)
    {
        col[vertex]=1; //there are 2 colors 1 and 0 you can choose any one of them at the initial stage
        queue<int>q;
        q.push(vertex);

        while(!q.empty())
        {
            int v=q.front();
            q.pop();

            for(auto i:adj[v])
            {
                if(col[i]==-1)
                {
                    col[i]=1-col[v]; //if parent color is 1 than adjacent i will become 0 and vice versa
                    q.push(i); //once colored push it into queue as we do in bfs to so we can traverse adjacents of this node later
                }
                else if(col[i]==col[v]) //means if the color of the adjacent is same as parent than it is not a bipartite graph
                return false;
            }
        }
    
    return true; //q become empty and we are able to color all the adjacent nodes in the proper manner therefore q become empty and we can return true;
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
    bool BipartiteCheckBFS(int v,vector<vector<int>>&prerequisite)
    {
        if(prerequisite.size()==0)
        return true;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);

        vector<int>col(v+1,-1); //initially we are coloring all the nodes with -1 means not yet colored

        for(int i=1;i<=v;i++)
        {
            if(col[i]==-1)
            {
                if(!BFS(i,adj,col)) // means if BFS is not true than return false
                return false;
            }
        }
    return true; //it means all the components of the graphs are true that is the reason we reached here
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prerequisite={{1,2},
                              {2,3},
                              {2,4},
                              {3,5},
                              {4,7},
                              {5,7},
                              {7,8},
                                  };
    int TotalVertex=8;
    cout<<M.BipartiteCheckBFS(TotalVertex,prerequisite);

return 0;
}