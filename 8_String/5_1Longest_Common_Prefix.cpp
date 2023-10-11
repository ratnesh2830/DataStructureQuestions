#include<vector>
#include<iostream>
using namespace std;

class Solution
{
    public:
    string LongestPrefix(vector<string>s)
    {
        string str=s[0];
        string res="";

        for(int i=1;i<s.size();i++)
        {
            for(int j=0;j<s[i].size();j++)
            {
                if(!str.empty())
                {
                    if(str[j]!=s[i][j])
                    {
                        break;
                    }
                    res=res+str[j];
                }
            }
            if(!res.empty())
            {
                str=res;
                res="";
            }
            else
            return res;
        }
    return str;
    }
};
int main()
{
    Solution M;
    vector<string>s={"flow", "flower", "flowht"};
    cout<<M.LongestPrefix(s);
return 0;
}