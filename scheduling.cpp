#include<bits/stdc++.h>
using namespace std;
int n=201;
long int A[201];
class job
{

    int weight,length;
    public:
    job(int w,int l)
    {
        weight=w;
        length=l;
    }
    int getw() const
    {
        return weight;
    }
    int getl() const
    {
        return length;
    }
};
class myComparator 
{ 
public: 
    int operator() (const job& p1, const job& p2) 
    { 
        if(p1.getw()-p1.getl() != p2.getw()-p2.getl())
        return p1.getw()-p1.getl() < p2.getw()-p2.getl();
        else
        {
            return p1.getw()<p2.getw();
        }
         
    } 
}; 
priority_queue <job, vector<job>, myComparator > pq; 
int main()
{
    ifstream file("jobs.txt");
    int n,w,l,i;
    long long int ft=0,sum=0;
    job temp(0,0);
    file>>n;
    for(i=0;i<n;i++)
    {
        file>>w;
        file>>l;
        pq.push(job(w,l));
    }
    for(i=0;i<n;i++)
    {
        temp=pq.top();
        pq.pop();
        ft+=temp.getl();
        sum+=ft*temp.getw();
     
    }
    cout<<sum;
}