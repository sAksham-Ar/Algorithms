#include <bits/stdc++.h> 
using namespace std; 
int n=10000;

int sum=0;
void med(int a[],int k)
{
    int i,m;
priority_queue <int, vector<int>, greater<int> > pq;
for(i=1;i<=k;i++)
{
  pq.push(a[i]);
}
i=1;
if(k%2!=0)
while(1)
{
    
    
    if(i==((k+1)/2))
    {
 m=pq.top();
 
break;
    }
    pq.pop();
    i++;
}
else
while(1)
{
  
    if(i==((k)/2))
    {
 m=pq.top();
break;
    }
      pq.pop();
    i++;
}
sum+=m;
} 
int main () 
{ 
    
    int x,a[10001],i=1,k=1; 
    
    ifstream file("med.txt");
    while(file>>x)
    {
        a[i]=x;
        i++;
    }
    for(k=1;k<10001;k++)
    med(a,k);
    cout<<sum%10000;
} 