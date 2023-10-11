//In this program we are going to set matrix to zeroes

#include<iostream>
using namespace std;

class Matrix
{
public:
    int A[3][3]={{1,0,1},{0,0,1},{1,1,1}};
    int n=3;
    int m=3;
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
                for(k=0;k<m;k++)
                {
                    if(A[i][k]!=0)
                     A[i][k]=-1;
                }
                for(k=0;k<n;k++)
                {
                    if(A[k][j]!=0)
                     A[k][j]=-1;
                }
            }
        }

    }

    for(i=0;i<n;i++)
    {   
        for(j=0;j<m;j++)
        {
            if(A[i][j]==-1)
               A[i][j]=0;
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
    cout<<endl;
    M.SetMatrix();
    M.Display();
return 0;
}