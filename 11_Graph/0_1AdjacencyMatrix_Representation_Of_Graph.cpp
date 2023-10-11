#include<iostream>
using namespace std;
#include<vector>



class Solution
{
    public:
    vector<vector<int>>djacencyMatrixRepresentation(int n,int m)//here n is the number of nodes and m is the number of edges
    {
        vector<vector<int>>vec(n+1,vector<int>(n+1,0)); //2d vector of size n+1*n+1 and filled all the values with 0
        for(int i=0;i<m;i++)
        {
            int u,v; //u and v are the pair of vertices of an edge
            cin>>u;
            cin>>v;

            vec[u][v]=1; //because it is an undirected graph
            vec[v][u]=1; //because it is an undirected graph
        } 
    return vec;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>GraphMatrix;
    GraphMatrix=M.djacencyMatrixRepresentation(5,5);
    for(int i=0;i<GraphMatrix.size();i++)
    {
        for(int j=0;j<GraphMatrix[i].size();j++)
        {
            cout<<GraphMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    
}