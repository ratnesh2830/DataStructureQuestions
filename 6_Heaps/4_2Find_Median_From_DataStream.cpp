#include<iostream>
#include<vector>
using namespace std;
#include<queue>

class Solution
{
    public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;

    public:
    void addNum(int nums)
    {
        int Lsize=maxheap.size();
        int Rsize=minheap.size();

        if(Lsize==0)
        {
            maxheap.push(nums);
        }
        else if(Rsize==0)
        {
            if(nums>maxheap.top())
            minheap.push(nums);

            else
            {
                int temp=maxheap.top();
                maxheap.pop();
                maxheap.push(nums);
                minheap.push(temp);
            }
        }
        else if(Lsize==Rsize)
        {
            if(nums<minheap.top())
            maxheap.push(nums);

            else
            {
                int temp=minheap.top();
                minheap.pop();
                minheap.push(nums);
                maxheap.push(temp);
            }
        }

        else if(Lsize>Rsize)
        {
            if(nums>maxheap.top())
            minheap.push(nums);

            else
            {
                int temp=maxheap.top();
                maxheap.pop();
                maxheap.push(nums);
                minheap.push(temp);
            }
        }
    }

    double MedianFromDatastream()
    {
        int Lsize=maxheap.size();
        int Rsize=minheap.size();
        
        if(Lsize>Rsize)
        {
            return maxheap.top();
        }
        else
        {
            return (maxheap.top()+minheap.top())/2.0;
        }
    }
};

int main()
{
    Solution M;
    M.addNum(5);
    cout<<M.MedianFromDatastream()<<endl;
    M.addNum(3);
    cout<<M.MedianFromDatastream()<<endl;
    M.addNum(4);
    cout<<M.MedianFromDatastream()<<endl;
    M.addNum(2);
    cout<<M.MedianFromDatastream()<<endl;
    M.addNum(6);
    cout<<M.MedianFromDatastream()<<endl;
return 0;
}