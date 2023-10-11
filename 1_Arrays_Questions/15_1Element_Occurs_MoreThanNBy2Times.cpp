#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
    public:
    int Occurance(vector<int> &vec)
    {
        int count=0;
        sort(vec.begin(),vec.end());
        int N=vec.size()/2;
        int x=vec[0];
        for(int i=0;i<vec.size();i++)
        {
            if(x==vec[i])
            {
                count++;
                if(count>N)
                break;
            }
            else
            {
                x=vec[i];
                count=1;
            }
        }
    return x;
    }

};

int main()
{
    vector<int> vec{4,1,2,3,4,4,4};
    Solution M;
    cout<<M.Occurance(vec);
return 0;
}
