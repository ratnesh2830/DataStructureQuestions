#include<iostream>
using namespace std;
#include<unordered_map>
#include<string>
class Solution
{
    public:
    int Substring(string &str)
    {
        if(str.size()==0)
        return 0;

        int l=0;
        int length=0;
        unordered_map<int,int>map;

        for(int r=0;r<str.length();r++)
        {
            if(map.find(str[r])!=map.end() && map[str[r]]>=l)
            {
                    l=map[str[r]]+1;    
            }

            length=max(length,r-l+1);
            map[str[r]]=r;
            
        }
    return length;
    }
};
int main()
{
    Solution S;
    string str="abcaabcdba";
    cout<<S.Substring(str);
return 0;
}