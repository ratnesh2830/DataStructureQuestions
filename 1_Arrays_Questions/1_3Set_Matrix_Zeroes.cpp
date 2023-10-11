#include<iostream>
using namespace std;

class Matrix
{
public:
    int A[3][3]={{0,1,1},{1,1,1},{1,1,1}};
    int n=3;
    int m=3;
    bool col=false,row=false;
public:
    void SetMatrix();
    void Display();
};

void Matrix::SetMatrix()
{
    int i,j,k;
    for(k=0;k<m;k++)
    {
        if(A[0][k]==0)
        row=true;
    }

    for(k=0;k<n;k++)
    {
        if(A[k][0]==0)
        col=true;
    }

    for(int i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(A[i][j]==0)
            {
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }

    for(i=1;i<n;i++)
    {
        if(A[i][0]==0)
        {
            for(k=1;k<m;k++)
            A[i][k]=0;
        }
    }

    for(j=1;j<n;j++)
    {
        if(A[0][j]==0)
        {
            for(k=1;k<n;k++)
            A[k][j]=0;
        }
    }

    if(row)
    {
        for(k=0;k<m;k++)
        A[0][k]=0;
    }
    if(col)
    {
        for(k=0;k<n;k++)
        A[k][0]=0;
    }
}

void Matrix::Display()
{
    int i,j;
    for(i=0;i<n;i++)
    {   
        for(j=0;j<m;j++)
        {
            cout<<A[i][j]<<" ";
        }
    cout<<endl;
    }
}

int main()
{
    Matrix M;
    M.Display();
    M.SetMatrix();
    cout<<endl;
    M.Display();

return 0;
}