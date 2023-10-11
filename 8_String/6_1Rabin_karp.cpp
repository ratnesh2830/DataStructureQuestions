#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int> RabinKarp(string text,string pat)
    {
        int n=text.size();
        int k=pat.size();
        vector<int>res;

        for(int i=0;i<n-k+1;i++)
        {
            int x=0;
            for(int j=0;j<k;j++)
            {
                if(text[i+j]!=pat[j])
                {
                    x=1;
                    break;
                }
            }
        if(x==0)
        {
            res.push_back(i);
        }
        }
    return res;
    }
};

int main()
{
    Solution M;
    string text="GEEKS FOR GEEKS";
    string pat="GEEK";
    vector<int>res=M.RabinKarp(text,pat);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}