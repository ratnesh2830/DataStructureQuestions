#include<iostream>
using namespace std;

class Solution
{
    public:
    bool isPalindrome(string s)
    {
        int n=s.size();
        for(int i=0,j=n-1;i<=j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
        }
    return true;
    }
    int MinimumElements(string str)
    {
        int count=0;
        while(str.size()>1)
        {
            if(isPalindrome(str))
            {
                break;
            }
            else
            {
                count++;
                str.erase(str.begin()+str.size()-1);
            }
        }
    return count;
    }
};
int main()
{
    Solution M;
    string str="abcaa";
    cout<<M.MinimumElements(str);
return 0;
}