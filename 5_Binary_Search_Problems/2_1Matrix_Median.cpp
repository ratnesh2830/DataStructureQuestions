#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
    public:
    int Median(vector<vector<int>>&matrix,int n,int m)
    {
        vector<int>vec;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                vec.push_back(matrix[i][j]);
            }
        }

        sort(vec.begin(),vec.end());
        return vec[(n*m)/2];
    }
};
int main()
{
    Solution M;
    vector<vector<int>>matrix{{1,3,6},
                              {2,5,9},
                              {3,6,9}};
    cout<<M.Median(matrix,3,3);
return 0;
}