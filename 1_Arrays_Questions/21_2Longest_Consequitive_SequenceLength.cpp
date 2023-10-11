#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_set>
class Solution
{
    public:

    int SequenceL(vector<int>&vec)
    {
        unordered_set<int>hashset;
        int Max=0;
        for(int i=0;i<vec.size();i++)
        {
            hashset.insert(vec[i]);
        }

        for(int i=0;i<vec.size();i++)
        {
            if(!hashset.count(vec[i]-1))
            {
                int num=vec[i];
                int lonseq=1;

                while(hashset.count(num+1))
                {
                    num+=1;
                    lonseq+=1;
                }
            Max=max(Max,lonseq);
            }
        }
    return Max;
    }

    
};

int main()
{
    Solution M;
    vector<int> vec{100,200,201,202,203,1,3,2,4,204};
    cout<<M.SequenceL(vec);
return 0;
}