#include<bits/stdc++.h>
using namespace std;

int n=501;
long int A[501];
long long cost=0;
bool B[501]={false};

class edge
{

    int dest,src;
    long int len;
    bool g;
    public:
    edge(int s,int d,long int l)
    {
        src=s;
        dest=d;
        len=l;
        g=false;
    }
    int gets() const
    {
        return src;
    }
    int getd() const
    {
        return dest;
    }
    long int getl() const
    {
        return len;
    }
    void getg()
    {
      g=true;
    }
    bool h()
    {
        return g;
    }
};
class myComparator 
{ 
public: 
    int operator() (const edge& p1, const edge& p2) 
    { 
        return p1.getl() > p2.getl(); 
    } 
}; 
priority_queue <edge, vector<edge>, myComparator > pq; 
void sd(vector<edge>v[])
{
    int i=0;
    A[1]=0;
    B[1]=true;
    long int l;
    edge f(0,0,0);
    for(i=0;i<v[1].size();i++)
    {
        pq.push(v[1][i]);
        
        }
        while(pq.size())
        {
           
          
                 f=pq.top();
                 pq.pop();
             
        
           if(B[f.getd()]==false)
        
           {
            A[f.getd()]=f.getl();
            B[f.getd()]=true;
            
            f.getg();
            for(i=0;i<v[f.getd()].size();i++)
            {
                 pq.push(v[f.getd()][i]);
                
            }
           }
           }
        
}

int main()
{
    vector<string> myString;
 int s,d,i=0,m,n;
 char c;
 long int l;
   vector<edge> v[501];
   string instruction,temp;
    ifstream file("edges.txt");
 file>>m;
 file>>n;
 while(file>>s)
 {
     file>>d;
     file>>l;
     v[s].push_back(edge(s,d,l));
     v[d].push_back(edge(d,s,l));
 }

sd(v);
long long sum=0;
priority_queue <int,vector<int>,greater<int>>f;
for(i=1;i<501;i++)
{

sum+=A[i];

}

cout<<sum;
}
