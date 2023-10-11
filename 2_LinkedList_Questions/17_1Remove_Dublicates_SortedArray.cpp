#include<iostream>
using namespace std;
#include<vector>
#include<set>

class Solution
{
    public:
    int RemoveDublicate(vector<int>&vec)
    {
        if(vec.empty())
        return 0;
        int i;
        int length;
        set<int>set;
        for(i=0;i<vec.size();i++)
        {
            set.insert(vec[i]);
        }
        i=0;
        for(auto it=set.begin();it!=set.end();it++)
        {
            vec[i++]=*it;
        }
        length=set.size();
    return length;
    }
};

int main()
{
    Solution M;
    vector<int> vec{1,1,1,2,2,3,3,3,3,4,4};
    cout<<M.RemoveDublicate(vec)<<endl;
    for(auto it:vec)
    {
        cout<<it<<" ";
    }
return 0;
}