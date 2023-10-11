#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    void function(int i,int j,vector<vector<int>>&matrix,int n,string path,vector<vector<int>>&vis,vector<string>&res,vector<int>&di,vector<int>&dj)
    {
        if(i==n-1 && j==n-1)
        {
            res.push_back(path);
            return;
        }

        string move="DLRU";
        for(int k=0;k<di.size();k++)
        {
            int nexti=i+di[k];
            int nextj=j+dj[k];

            if(nexti<n && nextj>=0 && nextj<n && nexti>=0 && !(vis[nexti][nextj]) && matrix[nexti][nextj]==1)
            {
                vis[i][j]=1;
            function(nexti,nextj,matrix,n,path+move[k],vis,res,di,dj);
                vis[i][j]=0;
            }
        }
    }
    vector<string>Ratmaze(vector<vector<int>>&matrix,int n)
    {
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>res;
        string path="";
        vector<int>di={1,0,0,-1};
        vector<int>dj={0,-1,1,0};
        if(matrix[0][0]==1)
        {
            function(0,0,matrix,n,path,vis,res,di,dj);
        }
    return res;
    }
};
int main()
{
    Solution M;
    vector<vector<int>>matrix={{1,1,1,1},{1,0,0,1},{1,0,0,1},{1,1,1,1}};
    vector<string>res;
    res=M.Ratmaze(matrix,4);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
return 0;
}