#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct Room
{
    int start;
    int end;
    int position;
};
bool comparator(Room m1,Room m2)
    {
        if(m1.end <m2.end)
        return true;
        
        else if(m1.end>m2.end)
        return false;
        
        else
        {
            if(m1.position<m2.position)
            return true;
            else
            return false;
        }
    }
class Solution
{
    public:

   
    void Meeting(int start[],int end[],int n)
    {
        Room m[n];
        for(int i=0;i<n;i++)
        {
            m[i].start=start[i];
            m[i].end=end[i];
            m[i].position=i+1;
        }
        sort(m,m+n,comparator); //because sort is a outside member it us used here via algorithm liberary thats why static is needed in comparator if you have called the comparator without the sort function than you dont need static
        int lastend=m[0].end;
        vector<int> res;
        res.push_back(m[0].position);

        for(int i=1;i<n;i++)
        {
            if(m[i].start>lastend)
            {
                lastend=m[i].end;
                res.push_back(m[i].position);
            }
        }

        sort(res.begin(),res.end());

        for(auto it:res)
        {
            cout<<it<<" ";
        }

    }
};

int main()
{
    Solution M;
    int start[]={1,3,0,5,8,5};
    int end[]={2,4,5,7,9,9};
    M.Meeting(start,end,6);
return 0;
}