#include<iostream>
using namespace std;

class Solution
{
    public:
    string LonhestPalindrome(string s)
    {
        int n=s.size();
        bool table[n][n]={0};
        int start,end;
        int length;
        string res="";
        for(int i=0;i<n;i++)
        {
            table[i][i]=true;
            start=i;
            end=i;
            length=1;
        }

        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                table[i][i+1]=true;
                start=i;
                end=i+1;
                length=2;
            }
        }

        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(table[i+1][j-1]==true && s[i]==s[j])
                {
                    table[i][j]=true;
                    start=i;
                    end=j;
                    length=k;
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
    string s="eeree";
    cout<<M.LonhestPalindrome(s);
return 0;
}