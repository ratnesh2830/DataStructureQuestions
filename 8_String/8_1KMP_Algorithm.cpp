#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int>KMP(string text,string pat)
    {
        vector<int>res;
        if(text=="" || pat=="")
        return res;

        int n=text.size();
        int k=pat.size();
        int LPS[k]={0};
        int i=1;
        int j=0;
        while(i<k)
        {
            if(pat[i]==pat[j])
            {
                LPS[i]=j+1;
                j++;
                i++;
            }
            else
            {
                if(j!=0)
                {
                j=LPS[j-1];
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }
        i=0;
        j=0;
        while(i<n)
        {
            if(text[i]==pat[j])
            {
                i++;
                j++;
                if(j==k)
                {
                    res.push_back(i-k);
                    j=LPS[j-1];
                }
            }
            else
            {
                if(j!=0)
                {
                    j=LPS[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
    return res;
    }
};
int main()
{
    Solution M;
    string text="AAAAABBAAAA";
    string pat="AAAA";
    vector<int>res=M.KMP(text,pat);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}
