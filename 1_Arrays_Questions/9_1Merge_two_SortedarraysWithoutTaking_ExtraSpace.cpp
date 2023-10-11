#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    void Merge(vector<int> &vec1,vector<int> &vec2)
    {
        int i,j;
        i=0;

        while(i<vec1.size())
        {
            if(vec1[i]>vec2[0])
            {
                swap(vec1[i],vec2[0]);
                i++;
                for(j=0;j<vec2.size()-1;j++)
                {
                    if(vec2[j]>vec2[j+1])
                    swap(vec2[j],vec2[j+1]);
                    else
                    break;
                }
            }
            else
            i++;
        }
    }
};

int main()
{
    Solution M;
    vector<int> vec1{1,5,9,10,15,20};
    vector<int> vec2{2,3,8,13};
    M.Merge(vec1,vec2);

    for(int i=0;i<vec1.size();i++)
    {
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<vec2.size();i++)
    {
        cout<<vec2[i]<<" ";
    }
    cout<<endl;
return 0;

}