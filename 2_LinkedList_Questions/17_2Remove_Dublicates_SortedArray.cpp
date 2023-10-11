#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    int RemoveDublicate(vector<int>&vec)
    {
        if(vec.empty())
        return 0;
        
        int j=0;
        int k=j+1;
        
       while(k<vec.size())
       {
        if(vec[j]==vec[k])
        {
            k++;
        }
        else
        {
            j++;
           vec[j]=vec[k];
            k++;
        }
       }
    return j+1;
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