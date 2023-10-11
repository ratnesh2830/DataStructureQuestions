#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class Solution
{
    public:
    vector<int> RabinKarp(string text,string pat)
    {
        int n=text.size();
        int k=pat.size();
        int d=256; //because there are total 256 characters so we took the maximum so that spurious hit chances will be very less
        int textcode=0;
        int patcode=0;
        int q=INT_MAX;
        vector<int>res;

        //lets find out the textcode and pattern code
        int l=k;
        int m=k;
        for(int i=0;i<k;i++)
        {
            textcode=textcode+(text[i]*pow(d,--l));
            textcode=textcode%q;
            patcode=patcode+(pat[i]*pow(d,--m));
            patcode=patcode%q;
        }

        for(int i=0;i<n-k+1;i++)
        {
            if(textcode==patcode)
            {   
                int j;
                for(j=0;j<k;j++)
                {
                    if(text[i+j]!=pat[j])
                    {
                        break;
                    }
                }
            if(j==k)
            {
                res.push_back(i);
            }
            }
            if(i<n-k)
            {   
                int hash=pow(d,k-1);
                textcode=(d*(textcode-text[i]*hash)+text[i+k])%q;

            }
        }
    
    return res;
        
    }
};

int main()
{
    Solution M;
    string text="RATNESHRAT";
    string pat="T";
    vector<int>res=M.RabinKarp(text,pat);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
return 0;
}