//In this program we are going to use the min and max heap to find the kth largest and smallest element by reducing the time complexity from nlogn to nlogk
#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
    public:

    int Kthlargest_minheap(vector<int>&vec,int k)
    {
        priority_queue<int>pq;

        for(int i=0;i<vec.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(-vec[i]);
            }
            else
            {
                if(-vec[i]<pq.top())
                {
                    pq.pop();
                    pq.push(-vec[i]);
                }
            }
        }
    return -pq.top();
    }

    int Kthsmallest_maxheap(vector<int>&vec,int k)
    {
        priority_queue<int>pq;

        for(int i=0;i<vec.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push(vec[i]);
            }
            else
            {
                if(vec[i]<pq.top())
                {
                    pq.pop();
                    pq.push(vec[i]);
                }
            }
        }
    return pq.top();
    }
};

int main()
{
    Solution M;
    vector<int> vec={10,5,2,6,7,3,4,9,8,1};
    cout<<M.Kthlargest_minheap(vec,3)<<endl;
    cout<<M.Kthsmallest_maxheap(vec,3);
return 0;
}