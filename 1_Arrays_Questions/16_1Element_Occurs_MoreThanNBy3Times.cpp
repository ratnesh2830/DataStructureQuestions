#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
    public:

    vector<int> Ocuur(vector<int> &vec)
    {
        vector<int> res;
        if(vec.size()==0)
        return res;

        int count=0,a,i;
        int N=vec.size()/3;
        sort(vec.begin(),vec.end());
        a=vec[0];
        for(i=0;i<vec.size();i++)
        {
            if(a==vec[i])
            {
                count++;
            }
            else
            {
                if(count>N)
                res.push_back(a);

                a=vec[i];
                count=1;
            }
        }
        if(count>N)
        res.push_back(a);
    return res;
    }
};

int main()
{
    Solution M;
    vector<int> vec{3,3,3,2,1,2,3,2,2};
    vector<int> res;
    res=M.Ocuur(vec);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
return 0;
}