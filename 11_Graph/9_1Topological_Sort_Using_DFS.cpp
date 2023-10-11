#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Solution
{
    private:
    void DFS(int vertex,vector<int>adj[],vector<int>&visi,stack<int>&st)
    {
        visi[vertex]=1;

        for(auto i:adj[vertex])
        {
            if(!visi[i])
            {
                DFS(i,adj,visi,st);
            }
        }
    st.push(vertex);
    }

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

    public:
    stack<int>TopologicalSortDFS(int v,vector<vector<int>>&prerequisite)
    {
        stack<int>st;
        if(prerequisite.size()==0)
        return st;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);

        vector<int>visi(v+1,0);

        for(int i=1;i<=v;i++)
        {
            if(!visi[i])
            {
                DFS(i,adj,visi,st);
            }
        }
    return st;
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
                              {9,7},
                              {7,8},
                              {8,9},
                              
                              };
    int TotalVertex=9;
    stack<int>st=M.TopologicalSortDFS(TotalVertex,prerequisite);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
return 0;
}