#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int> Zfunction(string text,string pat)
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
    string text="baabaa";
    string pat="aab";
    vector<int>res=M.Zfunction(text,pat);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}