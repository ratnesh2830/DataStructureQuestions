#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

class Solution
{
    public:

    bool isPossible(vector<int>&vec,int dist,int totalcows)
    {
        int count=1;
        int co_ordi=vec[0];

        for(int i=1;i<vec.size();i++)
        {
            if(dist<=vec[i]-co_ordi)
            {
                count++;
                if(count==totalcows)
                {
                    return true;
                }
                co_ordi=vec[i];
            }
        }
    return false;
    }
    int AggressiveCows(vector<int>&vec,int totalcows)
    {
        if(totalcows<2 || totalcows >vec.size())
        return -1;

        sort(vec.begin(),vec.end());
        int low=1;
        int high=vec[vec.size()-1]-vec[0];

        while(low<=high)
        {   
            int mid=(low+high)/2;
            if(isPossible(vec,mid,totalcows)==true)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    return high;
    }
};

int main()
{
    Solution M;
    vector<int>vec={1,2,8,4,9};
    cout<<M.AggressiveCows(vec,3);
return 0;
}