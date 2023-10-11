#include<iostream>
using namespace std;

class Solution
{
    public:
    string ReverseString(string s)
    {
        int left=0;
        int right=s.size()-1;
        string temp="";
        string ans="";

        while(left<=right)
        {
            char c=s[left];
            if(c!=' ')
            {
                temp=temp+c;
            }
            else if(c==' ')
            {
                if(ans!="")
                {
                    ans=temp+' '+ans;
                }
                else
                {
                    ans=temp;
                }
            temp="";
            }
        left++;
        }

    if(temp!="")
    {
        if(ans!="")
        ans=temp+' '+ans;
        else
        ans=temp;
    }
    
    

    return ans;
    }
};
int main()
{
    Solution M;
    string s="this";
    cout<<M.ReverseString(s);
    cout<<s.size();
return 0;
}