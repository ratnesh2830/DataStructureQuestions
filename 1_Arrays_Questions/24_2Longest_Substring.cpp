#include<iostream>
using namespace std;
#include<unordered_set>
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
        unordered_set<int>set;

        for(int r=0;r<str.length();r++)
        {
            if(set.find(str[r])!=set.end())
            {
                while(set.find(str[r])!=set.end())
                {
                    set.erase(str[l]);
                    l++;
                }
            }
            set.insert(str[r]);
            length=max(length,r-l+1);
        }
    return length;
    }
};
int main()
{
    Solution S;
    string str="takeUforward";
    cout<<S.Substring(str);
return 0;
}