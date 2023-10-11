//in this algorithm we are using sorting algorithm directly to find out the kth largest and smallest element
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
class Solution
{
    public:

    void Kthlargest_smallest(vector<int>&vec,int k)
    {
        sort(vec.begin(),vec.end());
        cout<<"kth largest element is "<<vec[vec.size()-k]<<endl;
        cout<<"kth smallest element is "<<vec[k-1];
    }
};

int main()
{
    Solution M;
    vector<int>vec={10,5,2,6,7,3,4,9,8,1};
    M.Kthlargest_smallest(vec,3);
return 0;
}