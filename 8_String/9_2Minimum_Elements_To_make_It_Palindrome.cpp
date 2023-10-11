#include<iostream>
using namespace std;

class Solution
{
    public:
    int MinimumElements(string str)
    {
        int n=str.size();
        int left=0;
        int right=n-1;
        int added=0;
        while(left<right)
        {
            if(str[left]==str[right])
            {
                left++;
                right--;
            }
            else
            {
                left=0;
                added=n-right;
                while(str[left]==str[right])
                {
                    left++;
                    added--;
                }
                right--;
            }
        }
    return added;
    }
};
int main()
{
    Solution M;
    string str="AACECAAAA";
    cout<<M.MinimumElements(str);
return 0;
}