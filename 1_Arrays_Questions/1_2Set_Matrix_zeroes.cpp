#include<iostream>
using namespace std;

class Matrix
{
public:
    int A[3][3]={{1,0,1},{0,0,1},{1,1,1}};
    int n=3;
    int m=3;
    int row[3]={0};
    int col[3]={0};
public:
    void SetMatrix();
    void Display();
};

void Matrix::SetMatrix()
{
    int i,j,k;
    
    for(i=0;i<n;i++)
    {   
        for(j=0;j<m;j++)
        {
            if(A[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }

    }

    for(i=0;i<n;i++)
    {
        if(row[i]==1)
        {
            for(k=0;k<m;k++)
            {
                A[i][k]=0;
            }
        }
    }

    for(j=0;j<m;j++)
    {
        if(col[j]==1)
        {
            for(k=0;k<m;k++)
            {
                A[k][j]=0;
            }
        }
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