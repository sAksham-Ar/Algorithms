#include<bits/stdc++.h>
using namespace std;

int k;
long int A[501];
long long cost=0;
int B[501];

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

    bool compare(const edge& p1, const edge& p2) 
    { 
        return p1.getl() < p2.getl(); 
    } 

void un(int s,int d)
{
  long int s1=A[s],d1=A[d];
   if(B[A[s]]>=B[A[d]])
   {
       for(int i=1;i<=k;i++)
       {
           if(A[i]==d1)
           {
               B[A[s]]+=B[A[i]];
               B[A[i]]=0;
           A[i]=A[s];
           }
       }
      
   }
   else
   {
     for(int i=1;i<=k;i++)
       {
           if(A[i]==s1)
           {
              
                B[A[d]]+=B[A[i]];
               B[A[i]]=0;
           A[i]=A[d];
           
           }
       }
     
   }
   
}
void cl(vector<edge>v)
{
    int i=0,n=k;
    for(i=1;i<=k;i++)
    A[i]=i;
    for(i=1;i<=k;i++)
    B[i]=1;
    i=0;
    while(n>4)
    {
     if(A[v[i].gets()]!=A[v[i].getd()])
     {
    
         un(v[i].gets(),v[i].getd());
         n--;
     }
      i++;
    }

   while(A[v[i].gets()]==A[v[i].getd()])
   {
       i++;
   }
   cout<<v[i].getl();
}

int main()
{
  
 int s,d,i=0,n;
 char c;
 long int l;
   vector<edge> v;
   string instruction,temp;
    ifstream file("cl.txt");
 file>>k;

 while(file>>s)
 {
     file>>d;
     file>>l;
     v.push_back(edge(s,d,l));
 }
sort(v.begin(),v.end(),compare);
cl(v);


}
