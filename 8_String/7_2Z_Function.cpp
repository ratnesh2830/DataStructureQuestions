#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int>Zfunction(string text,string pat)
    {
        vector<int>res;
        if(text=="" || pat=="")
        return res;

        int n=text.size();
        int k=pat.size();
        string str=pat+'$'+text;
        int m=str.size();
        int i=1;
        int j=0;
        vector<int>zfun(m,0);
        while(i<m)
        {
            if(str[i]==str[j])
            {
                zfun[i]=j+1;
                j++;
                i++;
            }
            else
            {
                if(j!=0)
                {
                    j=zfun[j-1];
                }
                else
                {
                    zfun[i]=0;
                    i++;
                }
            }
        }
    for(int i=0;i<zfun.size();i++)
    {
        if(zfun[i]==k)
        {
            res.push_back(i-(2*k)); //here 2 are $ that we have included and k-1 to get the starting index of the found pattern in text string
        }
    }
    return res;
    }
};

int main()
{
    Solution M;
    string text="baaabaaab";
    string pat="aab";
    vector<int>res=M.Zfunction(text,pat);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}