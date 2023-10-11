#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

class Solution
{
    public:
    bool isPossible(vector<int>&vec,int dis,int cows)
    {
        int count=1;
        int co_ordi=vec[0];
        for(int i=1;i<vec.size();i++)
        {
            if(dis<=vec[i]-co_ordi)
            {
                count++;
                if(count==cows)
                {
                    return true;
                }
                co_ordi=vec[i];
            }
        }
    return false;
    } 

    int AggressiveCows(vector<int>&vec,int cows)
    {

        if(cows<2 || cows>vec.size())
        return -1;

        sort(vec.begin(),vec.end());
        int maxdist=vec[vec.size()-1]-vec[0];
        int res=0;

        for(int i=1;i<=maxdist;i++)
        {
            if(isPossible(vec,i,cows)==true)
            {
                res=i;
            }
            else
            break;
        }
        
    return res;
    }
};

int main()
{
    Solution M;
    vector<int>vec={1,2,8,5,9};
    int totalCows=3;
    cout<<M.AggressiveCows(vec,totalCows);
return 0;
}