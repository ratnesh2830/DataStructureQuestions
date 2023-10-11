#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution
{
    public:

    //worst case which takes n square time complexity
    vector<int> TwoSum(vector<int>&vec,int x)
    {
        vector<int>res;
        int i,j;

        for(i=0;i<vec.size();i++)
        {
            for(j=i+1;j<vec.size();j++)
            {
                if(vec[i]+vec[j]==x)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        if(!res.empty())
        break;
        }
    return res;
    }

    //optimized case which will take nlogn time complexity 
    vector<int>TwoSum1(vector<int>&vec,int x)
    {
        vector<int>res;
        int i,j;
        sort(vec.begin(),vec.end());
        i=0;
        j=vec.size()-1;

        while(i<j)
        {
            if(vec[i]+vec[j]==x)
            {
                res.push_back(i);
                res.push_back(j);
                break;
            }
            else if(vec[i]+vec[j]>x)
            j--;

            else
            i++;
        }
    return res;
        
    }

};

int main()
{
    Solution M;
    vector<int> vec{2,3,4,5,9};
    vector<int>res;
    int target=7;
    res=M.TwoSum1(vec,target);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
return 0;
}