#include<iostream>
using namespace std;

class rotate
{
    public:
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3]={0};
    int n=3;

    public:

    void Rmatrix();
    void Display1();
    void Display2();
};

void rotate::Rmatrix()
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            B[j][n-1-i]=A[i][j];
        }
    }
}

void rotate::Display1()
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
void rotate::Display2()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<B[i][j]<<" ";
        }
    cout<<endl;
    }
}

int main()
{
    rotate M;
    M.Display1();
    M.Rmatrix();
    cout<<endl;
    M.Display2();
return 0;
}