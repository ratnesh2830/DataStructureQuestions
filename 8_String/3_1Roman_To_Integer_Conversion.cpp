#include<iostream>
using namespace std;

class Solution
{
    public:

    int value(char r)
    {
        if(r=='I')
        return 1;

        else if(r=='V')
        return 5;

        else if(r=='X')
        return 10;

        else if(r=='L')
        return 50;

        else if(r=='C')
        return 100;

        else if(r=='D')
        return 500;

        else if(r=='M')
        return 1000;
    
    return -1;
    }

    int RomanToInteger(string s)
    {
        int n=s.size();
        int res;

        for(int i=0;i<n;i++)
        {
            int s1=value(s[i]);
            
            if(i+1<n)//checking if next element is present in the string or not
            {
                int s2=value(s[i+1]);
                {
                    if(s1<s2)
                    {
                        res=res+s2-s1;
                        i++;
                    }
                    else
                    {
                        res=res+s1;
                    }
                }
            }
            else
            {
                res=res+s1;
            }
        }
    return res;
    }
};

int main()
{
    Solution M;
    string s="MCMIV";
    cout<<M.RomanToInteger(s);
return 0;
}