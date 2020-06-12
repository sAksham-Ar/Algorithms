#include<bits/stdc++.h>
using namespace std;
double dist(pair<double,double> a,pair<double,double> b)
{
    return powl(a.first-b.first,2)+powl(a.second-b.second,2);
}
double dist1(pair<double,double> a,pair<double,double> b)
{
    return pow(a.first-b.first,2)+pow(a.second-b.second,2);
}
int main()
{
    double sum=0;
    double x,y,min,min1;
    long n,a,i=1,j,idx=1,f=0;
    bool B[33709]={false};
    pair<double,double> A[33709];
    ifstream file("tspgreedy.txt");
    file>>n;
    while(file>>a)
    {
        file>>x;
        file>>y;
        A[a].first=x;
        A[a].second=y;
    }
    while(i<=n)
    {

     
        B[i]=true;
        min=__LONG_MAX__;
        idx=LONG_MAX;
        f=0;
        for(j=2;j<=n;j++)       
        {
            if(B[j]==false)
            {
            f=1;            
              if(dist(A[i],A[j])<min)
              {
              min=dist(A[i],A[j]);
              min1=dist1(A[i],A[j]);
              idx=j;
              }

            else if(dist(A[i],A[j])==min)
            {
                if(j<idx)
                {
                    min=dist(A[i],A[j]);
                    min1=dist1(A[i],A[j]);
                    idx=j;
                }
            }

            }

        }
        if(f==1)
        {
        sum+=sqrt(min1);
        
     //   cout<<idx<<' ';
        }
        else
        {
            sum+=sqrt(dist1(A[1],A[i]));
            break;
        }
         i=idx;
        
    }
    cout<<setprecision(15)<<sum;

}