#include<iostream>
using namespace std;
class Solution
{
    public:
    string CountandSay(int n)
    {
        if(n==1)
        return "1";
        if(n==2)
        return "11";

        string str="11";
        int count=1;
        for(int i=3;i<=n;i++)
        {
            str=str+'$';
            string t="";
            
                for(int j=1;j<str.size();j++)
                {
                    if(str[j]!=str[j-1])
                    {
                        t=t+to_string(count);
                        t=t+str[j-1];
                        count=1;
                    }
                    else
                    {
                        count++;
                    }
                }
            str=t;
        }
    return str;
    }
};
int main()
{
    Solution M;
    cout<<M.CountandSay(5);
return 0;
}