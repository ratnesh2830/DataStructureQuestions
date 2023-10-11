//In this program we are going to print all the possible permutation of the given set
#include<iostream>
using namespace std;

class Permutation
{
public:
    void Perm(int A[],int k);
};

void Permutation::Perm(int A[],int k)
{
    static int flag[3]={0};
    static int res[3];
    static int x=0;
    int i,n=3;

    if(k>=n)
    {
        if(x==1)
        {   
            cout<<"Next permutation is:";
            for(i=0;i<n;i++)
            {
                cout<<res[i]<<" ";
            }
        exit(0);

        }
        if(res[0]==2 && res[1]==3 && res[2]==1)
        {
            x=1;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                res[k]=A[i];
                flag[i]=1;
                Perm(A,k+1);
                flag[i]=0;
            }
        }
    }

}
int main()
{
    Permutation P;
    int A[3]={1,2,3};
    P.Perm(A,0);
return 0;
}