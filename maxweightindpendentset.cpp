#include<bits/stdc++.h>
using namespace std;
long long A[1001],B[1001];
int main()
{
 int n,i;
 ifstream file("mwis.txt");
 file>>n;
 vector<int> vert;
 for(i=1;i<=n;i++)
 {
     file>>B[i];
 }
 A[0]=0;
 A[1]=B[1];
 for(i=2;i<=n;i++)
 
 A[i]=max(A[i-1],A[i-2]+B[i]);
 for(i=n;i>=1;i--)
 {
     if((A[i-2]+B[i])>A[i-1])
     {
     vert.push_back(i);
     i--;
     }

 }
 cout<<A[n];
 for(i=0;i<vert.size();i++)
 cout<<vert[i]<<' ';
}
