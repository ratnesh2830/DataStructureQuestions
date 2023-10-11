#include<iostream>
using namespace std;
class Solution
{
    public:
    int CompaeVersion(string str1,string str2)
    {
        if(str1=="" && str2=="")
        return 0;

        int n=str1.size();
        int m=str2.size();
        int i=0,j=0;
        while(i<n || j<m)
        {
            int num1=0;
            int num2=0;

            while(i<n && str1[i]!='.')
            {
                num1=10*num1+(str1[i]%48);
                i++;
            }

            while(j<m && str2[j]!='.')
            {
                num2=10*num2+(str2[j]%48);
                j++;
            }
        
        i++;
        j++;

        if(num1<num2)
        return -1;

        if(num1>num2)
        return 1;
        }
    return 0;
    }
};
int main()
{
    Solution M;
    string str1="1.0005";
    string str2="1.05.1.1";
    cout<<M.CompaeVersion(str1,str2);
return 0;
}