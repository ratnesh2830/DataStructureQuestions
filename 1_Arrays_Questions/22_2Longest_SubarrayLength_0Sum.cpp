#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>

class Solution
{
    public:
    int LengthSub(vector<int>&vec)
    {
        int maxi=0;
        unordered_map<int,int> hashmap;
        int sum=0;
        if(vec.empty())
        return 0;
        
        for(int i=0;i<vec.size();i++)
        {
            sum=sum+vec[i];

            if(sum==0)
            {
                maxi=i+1;
            }
            else
            {
                if(hashmap.find(sum)!=hashmap.end())
                {
                    maxi=max(maxi,i-hashmap[sum]);
                }
                else
                {
                    hashmap[sum]=i;
                }
            }
        }
    return maxi;
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,-1,3,2,-2,-8,1,7,10,23};
    cout<<M.LengthSub(vec);
return 0;
}