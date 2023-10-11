#include<iostream>
using namespace std;
#include<vector>
#include<list>

class Solution
{
    public:
    vector<int>* AdjacenecyListRepresentation(int n,int m)//number of vertices are n and number of edges are m
    {
        vector<int>*vec=new vector<int>[n+1]; 
        

        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
       
    return vec;
    }

};

int main()
{
Solution M;
vector<int>*res=M.AdjacenecyListRepresentation(5,5);
cout<<endl;
for(int i=1;i<6;i++) //here 5+1 is the total number of vertices because it is one based indexing you can also do i<=5
{   
    cout<<i<<"->";
    for(int j=0;j<res[i].size();j++)
    {
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}