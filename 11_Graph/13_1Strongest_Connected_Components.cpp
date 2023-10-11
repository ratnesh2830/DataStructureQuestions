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

        for(int i:adj[vertex])
        {
            if(!visi[i])
            DFS(i,adj,visi,st);
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

    void TransposeGraph(vector<int>trans[],vector<int>adj[],int v,vector<int>&visi)
    {
        for(int i=1;i<=v;i++)
        {
            visi[i]=0; //making all the vertex again non visited
            for(int j:adj[i])
            {
                trans[j].push_back(i);
            }
        }
    }
    void ReverseDFS(int vertex,vector<int>trans[],vector<int>&visi,vector<int>&vec)
    {
        visi[vertex]=1;
        vec.push_back(vertex);

        for(auto i:trans[vertex])
        {
            if(!visi[i])
            ReverseDFS(i,trans,visi,vec);
        }
    }

    public:
    vector<vector<int>> StrongestConnectedComponents(int v,vector<vector<int>>&prerequisite)
    {
        vector<vector<int>>res;

        if(prerequisite.size()==0)
        return res;

        vector<int>adj[v+1];
        Implementation(adj,prerequisite);

        stack<int>st;
        vector<int>visi(v+1,0);
        for(int i=1;i<=v;i++)
        {
            if(!visi[i])
            {
                DFS(i,adj,visi,st); //find the topological order using DFS traversal and storing it in stack
            }
        }
        
        vector<int>trans[v+1];
        TransposeGraph(trans,adj,v,visi); //doing the transpose of the given graph
        while(!st.empty())
        {
            int i=st.top();
            st.pop();
            vector<int>vec;

            
            if(!visi[i])
            {
            
            ReverseDFS(i,trans,visi,vec); //finding the strongly connected components of the given graph
            res.push_back(vec);
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
                              {3,4},
                              {3,5},
                              {4,1},
                              {5,6},
                              {6,7},
                              {7,8},
                              {8,6},
                                  };
    int TotalVertex=8;
    vector<vector<int>>res=M.StrongestConnectedComponents(TotalVertex,prerequisite);

    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j];
        }
    cout<<endl;
    }
return 0;
}
