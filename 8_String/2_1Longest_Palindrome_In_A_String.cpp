#include<iostream>
using namespace std;

class Solution
{
    public:
    string LongestPalindrome(string s)
    {
      string res="";
      int n=s.size();
      int length=INT_MIN;
      int start;
      int end;
      int newi;
      int newj;
      
      for(int i=0;i<n;i++)
      {
        for(int j=i;j<n;j++)
        {
            newi=i;
            newj=j;
            while(newi<=newj)
            {
                if(s[newi]!=s[newj])
                break;
                else
                {
                    newi++;
                    newj--;
                }
            }
        if(newi>newj)
        {
            if(length<(j-i+1))
            {
                start=i;
                end=j;
            }
            length=max(length,(j-i+1));
        }
        }
    }
    for(int i=start;i<=end;i++)
    {
        res=res+s[i];
    }
    
    return res;
    }
};

int main()
{
    Solution M;
    string s="forgeeksskeegfor";
    cout<<M.LongestPalindrome(s);
return 0;
}