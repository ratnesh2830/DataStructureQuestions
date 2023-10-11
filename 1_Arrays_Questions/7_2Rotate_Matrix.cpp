#include<iostream>
using namespace std;

class rotate
{
    public:
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3,temp;

    public:

    void Rmatrix();
    void Display();
};

void rotate::Rmatrix()
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            temp=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }
    }
    
    for(i=0;i<n;i++)
   {
            temp=A[i][0];
            A[i][0]=A[i][n-1];
            A[i][n-1]=temp;
    }
}

void rotate::Display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<A[i][j]<<" ";
        }
    cout<<endl;
    }
}

int main()
{
    rotate M;
    M.Display();
    M.Rmatrix();
    cout<<endl;
    M.Display();
return 0;
}
