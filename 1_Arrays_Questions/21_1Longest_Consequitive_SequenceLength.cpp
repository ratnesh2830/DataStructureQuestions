#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
class Solution
{
    public:
    int SequenceL(vector<int> &vec)
    {
        vector<int> res;
        if(vec.empty())
        return 0;

        int count=1;
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size()-1;i++)
        {
            if(vec[i]==vec[i+1]-1)
            count++;
            else
            {
                res.push_back(count);
                count=1;
            }
        }
    int a=*max_element(res.begin(),res.end());
    return a;
    }
};

int main()
{
    Solution M;
    vector<int> vec{100,200,1,3,2,4,101,102,103,104};
    cout<<M.SequenceL(vec);
return 0;
}