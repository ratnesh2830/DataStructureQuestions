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
    bool BFScycleCheck(int v,vector<vector<int>>&prerequisite)
    {
        if(prerequisite.size()==0)
        return false;

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
        int count=0;
        while(!q.empty())
        {
            int vertex=q.front();
            q.pop();
            count++;
            for(auto i:adj[vertex])
            {
                Indeg[i]--;
                if(Indeg[i]==0)
                q.push(i);
            }
        }
        if(count!=v)//if count is does not equal to the total number of nodes than it is a cyclic directed graph
            {
            return true;
            }

    return false;
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
                              {6,5},
                              {6,7},
                              {7,8},
                              {8,9},
                              {9,7},
                              };
    int TotalVertex=9;
    cout<<M.BFScycleCheck(TotalVertex,prerequisite);
return 0;
}