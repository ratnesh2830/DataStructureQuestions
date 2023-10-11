#include<iostream>
using namespace std;

class Solution
{
    public:
    int StringToInt(string s)
    {
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            res=(10*res)+(s[i]%48);
            
        }
    return res;
    }
};
int main()
{
    Solution M;
    cout<<M.StringToInt("1234");
return 0;
}
