#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:
    vector<int> Majority(vector<int> &vec)
    {
        vector<int> res;
        if(vec.size()==0)
        return res;
        int N=vec.size()/3;
        int num1=1,num2=-1,count1=0,count2=0;

        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==num1)
            count1++;

            else if(vec[i]==num2)
            count2++;

            else if(count1==0)
            {
            num1=vec[i];
            count1++;
            }  

            else if(count2==0)
            {
            num2=vec[i];
            count2++;
            }

            else
            {count1--;
            count2--;
            }
        }
    for(int i=0;i<vec.size();i++)
        {
            if(num1==vec[i])
                count1++;
            if(num2==vec[i])
                count2++;
        }
        if(count1>N)
        res.push_back(num1);
        if(count2>N)
        res.push_back(num2);
    
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{2,2,3,3,3,1,2};
    vector<int> res;
    res=M.Majority(vec);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
return 0;
}