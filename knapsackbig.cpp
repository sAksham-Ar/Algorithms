

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long *v,*w,*A,m,n,i=1,a,b,j,*B;
    ifstream file("knapsackb.txt");
    file>>m;
    file>>n;
    v=new long long[n+1];
    w=new long long[n+1];
    A=new long long[m+1];
    B=new long long[m+1];
    i=1;
    while(file>>a)
    {
        v[i]=a;
        file>>b;
        w[i]=b;
        i++;
    }
    for(j=0;j<=m;j++)
    A[j]=0;
   
    
    for(i=1;i<=n;i++)
    {
        
        for(j=0;j<=m;j++)
        {  
            if(j>=w[i])
            {
                
            B[j]=max(A[j],A[j-w[i]]+v[i]);
            }

            else
            {
                B[j]=A[j];
            }
            

        }
         copy(B,B+m+1,A);
    }
   cout<<A[m];

}