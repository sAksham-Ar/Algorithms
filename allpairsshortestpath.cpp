#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,s,d,l,k,f=1;
    long m;
   vector<long int> A[1001],B[1001],edges[1001];
   for(i=0;i<=1000;i++)
   {
       A[i].reserve(1001);
       B[i].reserve(1001);
       edges[i].assign(1001,INT_MIN);
   }
 ifstream file("g3.txt");

 file>>n;
 file>>m;
 
while(file>>s)
 {
     file>>d;
   
     file>>l;
    if(edges[s][d]==INT_MIN)
    edges[s][d]=l;
    else if(l<edges[s][d])
    {
        edges[s][d]=l;
    }
    
 }
 
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        if(i==j)
        {
            A[i][j]=0;
        }
        else if(edges[i][j]==INT_MIN)
        {
        A[i][j]=INT_MAX/2;
        }
        else
        {
            A[i][j]=edges[i][j];
        }
        
    }
}

for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        
        
            B[i][j]=min(A[i][j],A[i][k]+A[k][j]);
        
        
    }
  
}
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        A[i][j]=B[i][j];
    }
}
}



for(i=1;i<=n;i++)
{
    if(A[i][i]<0)
    {
        f=0;
        break;
    }
}
if(f==0)
cout<<"NULL";
else
{
    long min=INT_MAX;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
          if((i!=j)&&(A[i][j]<min))
          min=A[i][j];
        }
    }
    cout<<min;
}

return 0;
}