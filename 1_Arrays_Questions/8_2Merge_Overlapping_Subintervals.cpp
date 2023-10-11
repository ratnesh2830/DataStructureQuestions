#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

 class Solution
{
    public:

   vector<vector<int>> Merge(vector<vector<int>> vec)
    {
        vector<vector<int>> result;
        vector<int> temp;
        if(vec.empty() || vec[0][0]==0)
        {
            return result;
        }
        sort(vec.begin(),vec.end());
        temp=vec[0];
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i][0]<=temp[1])
            {
                temp[1]=max(temp[1],vec[i][1]);
            }
            else
            {
                result.push_back(temp);
                temp=vec[i];
            }
        }
        result.push_back(temp);
    return result;
    }
};

int main()
{
    Solution M;
    vector<vector<int>> vec{{1,3},{2,6},{8,10},{11,13}};
    vector<vector<int>> result;
    result=M.Merge(vec);
    
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i][0]<<","<<result[i][1]<<endl;
    }

return 0;
}