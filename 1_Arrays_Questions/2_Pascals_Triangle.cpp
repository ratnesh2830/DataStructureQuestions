#include<iostream>
using namespace std;

class Pascal
{
public:
    int n=5;
    int A[5][5]={0};
public:
    void PascalTriangle();
    int Rpascal(int n,int r);
    void Display();
};

int Pascal::Rpascal(int n,int r)
{
    if(n==r||r==0)
    return 1;

return Rpascal(n-1,r-1)+Rpascal(n-1,r);
}

void Pascal::PascalTriangle()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=n-i-1;j<n;j++)
        {
            if(j==n-1)
            A[i][j]=1;
            else
            A[i][j]=A[i-1][j]+A[i-1][j+1];
        }
    }
}

void Pascal::Display()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i][j]==0)
            cout<<" ";
            else
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Pascal P;
    //P.PascalTriangle();
    //P.Display();
    //cout<<endl;
    cout<<P.Rpascal(4,3);
return 0;
}