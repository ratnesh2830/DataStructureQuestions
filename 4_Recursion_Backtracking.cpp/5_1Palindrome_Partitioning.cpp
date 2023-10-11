#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:
    bool IsPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
    return true;
    }
    void function(int index,string s,vector<vector<string>>&res,vector<string>&ds)
    {
        if(index==s.length())
        {
            res.push_back(ds);
            return;
        }

        for(int i=index;i<s.size();i++)
        {
            if(IsPalindrome(s,index,i))
            {
                ds.push_back(s.substr(index,i-index+1));
                function(i+1,s,res,ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>>Partition(string s)
    {
        vector<vector<string>>res;
        vector<string>ds;
        function(0,s,res,ds);
        return res;
    }
};

int main()
{
    Solution M;
    string s="aabd";
    vector<vector<string>>res;
    res=M.Partition(s);
    for(int i=0;i<res.size();i++)
      {
         for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<" ";
           }
      cout<<endl;
      }
return 0;
}