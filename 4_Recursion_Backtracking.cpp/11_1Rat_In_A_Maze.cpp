#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    void function(int i,int j,vector<vector<int>>&matrix,int n,string path,vector<vector<int>>&vis,vector<string>&res)
    {
        if(i==n-1 && j==n-1)
        {
            res.push_back(path);
            return;
        }

        if(i+1<n && !(vis[i+1][j]) && matrix[i+1][j]==1)
        {
            vis[i][j]=1;
            function(i+1,j,matrix,n,path+'D',vis,res);
            vis[i][j]=0;
        }

        if(j-1>=0 && !(vis[i][j-1]) && matrix[i][j-1]==1)
        {
            vis[i][j]=1;
            function(i,j-1,matrix,n,path+'L',vis,res);
            vis[i][j]=0;
        }

        if(j+1<n && !(vis[i][j+1]) && matrix[i][j+1]==1)
        {
            vis[i][j]=1;
            function(i,j+1,matrix,n,path+'R',vis,res);
            vis[i][j]=0;
        }

        if(i-1>=0 && !(vis[i-1][j]) && matrix[i-1][j]==1)
        {
            vis[i][j]=1;
            function(i-1,j,matrix,n,path+'U',vis,res);
            vis[i][j]=0;
        }
    }

    vector<string>Ratmaze(vector<vector<int>>&matrix,int n)
    {
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>res;
        string path="";
        if(matrix[0][0]==1)
        {
            function(0,0,matrix,n,path,vis,res);
        }        
    return res;
    }
};

int main()
{
    Solution M;
    vector<vector<int>>matrix{{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,1}};
    vector<string>res;
    res=M.Ratmaze(matrix,4);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
return 0;
}