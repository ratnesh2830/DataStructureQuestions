#include<iostream>
using namespace std;
#include<unordered_set>
#include<string.h>
class Solution
{
  public:
  int Substring(string str)
  {
    int maxi=INT_MIN;
    int count=0;
    if(str.empty())
    return 0;

    for(int i=0;i<str.length();i++)
    {
      unordered_set<int> hashset;
      for(int j=i;j<str.length();j++)
      {
        if(hashset.find(str[j])!=hashset.end())
        {
          maxi=max(maxi,j-i);
          break;
        }
        else
        {
          hashset.insert(str[j]);
        }
      }
    }
  return maxi;
  }
};

int main()
{
  Solution M;
  string str="aabaa";
  cout<<M.Substring(str);
return 0;
}