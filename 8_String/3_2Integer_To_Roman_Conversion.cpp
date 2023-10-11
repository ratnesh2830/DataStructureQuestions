#include<iostream>
using namespace std;
#include<vector>
#include<utility>

class Solution
{
    public:
    string IntegertoRoman(int num)
    {
        vector<pair<int,char>>vec(7);
        vec[0]={1,'I'};
        vec[1]={5,'V'};
        vec[2]={10,'X'};
        vec[3]={50,'L'};
        vec[4]={100,'C'};
        vec[5]={500,'D'};
        vec[6]={1000,'M'};

        string res="";
        int i=6;
        while(num!=0)
        {
            if(num%vec[i].first != num)
            {
                int a=num/vec[i].first;
                while(a)
                {
                    res=res+vec[i].second;
                    a--;
                }
                num=num%vec[i].first;
                i--;
            }
            else
            {
                i--;
            }
        }
    return res;
    }
};

int main()
{
    Solution M;
    cout<<M.IntegertoRoman(324);
return 0;
}