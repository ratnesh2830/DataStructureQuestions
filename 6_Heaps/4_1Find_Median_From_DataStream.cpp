#include<iostream>
#include<vector>
using namespace std;

class Solution
{
    public:

    void MedianFromFlowingData(vector<int>&vec)
    {
        int count=1;
        cout<<"median of the total 1 elements = "<<vec[0]<<endl;

        for(int i=1;i<vec.size();i++)
        {
            int x=vec[i];
            int j=i-1;

            while(j>=0 && vec[j]>x)
            {
                vec[j+1]=vec[j];
                j--;
            }
        vec[j+1]=x;
        count++;

        if(count%2==0)
        cout<<"median of the total "<<count<<" elements = "<<(vec[count/2]+vec[(count/2)-1])/2.0<<endl;  //for 0 based indexing
        else
        cout<<"median of the total "<<count<<" elements = "<<vec[count/2]<<endl;
        }   
    }
};

int main()
{
    Solution M;
    vector<int>vec={ 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    M.MedianFromFlowingData(vec);
return 0;
}
