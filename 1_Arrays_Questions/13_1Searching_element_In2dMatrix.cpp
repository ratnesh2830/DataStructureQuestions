#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    bool Searching(vector<vector<int>> &vec,int target)
    {
        int i,j;
        cout<<vec.size()<<endl;
        for(i=0;i<vec.size()-1;i++)
        {
            if(target==vec[i][0] || target==vec[i+1][0])
                return true;
            else if(target>vec[i][0] && target<vec[i+1][0])
                break;
        }
    cout<<i<<endl;
    
    if(i==vec.size()-1)
    {
        for(j=0;j<vec[i].size();j++)
        {
            if(target==vec[i][j])
            return true;
            
        }
    }
    else
    {
        for(j=0;j<vec[i].size();j++)
        {
            if(target==vec[i][j])
            return true;
        }
    }
    return false;

    }
};

int main()
{
    Solution M;
    vector<vector<int>> vec{{1,3,5,7},
                            {10,11,16,20},
                            {23,30,34,60}};
    int target=61;
    bool a;
    a=M.Searching(vec,target);
    if(a==true)
    cout<<"element is present"<<endl;
    else
    cout<<"element is not present"<<endl;
return 0;
}