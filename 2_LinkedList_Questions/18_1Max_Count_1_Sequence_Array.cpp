#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int CountMax1(vector<int>&vec)
    {
        if(vec.empty())
        return 0;

        int count=0,length=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==1)
            {
            count++;
            length=max(length,count);
            }
            else
            count=0;
           
        }
    return length;
    }
};
int main()
{
    Solution M;
    vector<int> vec{0,1,1,1,0,0,1,1,0,0,1,1,1,1};
    cout<<M.CountMax1(vec);
return 0;
}