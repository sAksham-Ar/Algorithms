#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long *v,*w,**A,m,n,i=1,a,b,j;
    ifstream file("knapsack.txt");
    file>>m;
    file>>n;
    v=new long long[n+1];
    w=new long long[n+1];
    A=new long long*[n+1];
    for(i=0;i<=n;i++)
    A[i]= new long long[m+1];
    i=1;
    while(file>>a)
    {
        v[i]=a;
        file>>b;
        w[i]=b;
        i++;
    }
    for(j=0;j<=m;j++)
    A[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {  
            if(j>=w[i])
            A[i][j]=max(A[i-1][j],A[i-1][j-w[i]]+v[i]);
            else
            {
                A[i][j]=A[i-1][j];
            }
            

        }
    }
    cout<<A[n][m];

}