#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    bool IsSafe(int vertex,bool graph[101][101],vector<int>&ds,int col)
    {
        for(int k=0;k<ds.size();k++)
        {
            if(k!=vertex && graph[vertex][k]==1 && ds[k]==col)
            return false;
        }
    return true;
    }

    bool Function(int vertex,bool graph[101][101],vector<int>&ds,int m)
    {
        if(vertex==ds.size())
        return true;

        for(int i=1;i<=m;i++)
        {
            if(IsSafe(vertex,graph,ds,i))
            {
                ds[vertex]=i;
                if(Function(vertex+1,graph,ds,m))
                return true;
                else
                ds[vertex]=0;
            }
        }
    return false;
    }

    bool graphcoloring(bool graph[101][101],int n,int m)
    {
        vector<int>ds(n,0);

        if(Function(0,graph,ds,m))
        return true;

    return false;
    }
};
int main()
{
    Solution M;
    bool graph[101][101]={{0,1,1,0},
                          {1,0,1,0},
                          {0,1,1,0},
                          {1,0,1,0}};
    int n=4;
    int m=3;
    cout<<M.graphcoloring(graph,n,m);
return 0;
}