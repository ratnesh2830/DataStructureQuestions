#include<iostream>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
    bool Anagram(string str1,string str2)
    {
        if(str1.size()!=str2.size())
        return false;

        unordered_map<char,int>map;

        for(int i=0;i<str1.size();i++)
        {
            map[str1[i]]++;
            map[str2[i]]--;
        }

        for(auto it:map)
        {
            if(it.second!=0)
            return false;
        }
    return true;
    }
};

int main()
{
    Solution M;
    string str1="listen";
    string str2="silent";
    cout<<M.Anagram(str1,str2);
return 0;
}