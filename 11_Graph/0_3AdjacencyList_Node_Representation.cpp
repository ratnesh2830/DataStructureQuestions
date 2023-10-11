#include<iostream>
using namespace std;
#include<vector>


struct Node
{
    int value;
    vector<Node*>neighbour;
};
class Solution
{
    public:
    Node *Representation(int v,vector<vector<int>>&prere)
    {
        vector<Node*>vec(v+1,NULL);
        Node *temp1,*temp2;
        for(int i=0;i<prere.size();i++)
        {
            if(vec[prere[i][0]]!=NULL)
            {
                temp1=vec[prere[i][0]];
            }
            else
            {
                temp1=new Node;
                temp1->value=prere[i][0];
                vec[prere[i][0]]=temp1;
            }

            if(vec[prere[i][1]]!=NULL)
            {
                Node *temp2=vec[prere[i][1]];
            }
            else
            {
                temp2=new Node;
                temp2->value=prere[i][1];
                vec[prere[i][1]]=temp2;
            }

            temp1->neighbour.push_back(temp2);
            temp2->neighbour.push_back(temp1);
        }
    return vec[0];
    }
};

int main()
{
    Solution M;
    vector<vector<int>>prere={{1,2},
                              {1,3},
                              {1,4},
                              {4,5},
                              {4,6},
                              
                                    };
    Node *root=M.Representation(6,prere);
return 0;
}