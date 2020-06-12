#include<bits/stdc++.h>
using namespace std;


bitset<14> b1((int)pow(2,14)-1),b2;
unordered_map<bitset<14>,long long > m1;
double dist(pair<double,double> a,pair<double,double> b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}
void bitmask(int n,int m,int i,int z)
{
    if(m==0)
    {
        m1.insert(make_pair(b2,z));

    }
    else if(i==n)
    {
        return;
    }
    else
    {
        bitmask(n,m,i+1,z);
        b2.flip(i);
        bitmask(n,m-1,i+1,z);
        b2.flip(i);
    }
}

int main()
{
    
   
    unordered_map<bitset<14>,long long >::iterator itr;
    int j,a,c,n,d;
    double x,y;
   
    pair<double,double> B[14];
    ifstream file("tsp1.txt");
    file>>n;
    double A[(int)pow(2,14)][14];
    double min;

       j=0;
  while(file>>x)
  {
      file>>y;
      B[j].first=x;
      B[j].second=y;
      j++;
       

  }

   for(j=0;j<n;j++)
    {
        
        b2=b1;
        bitmask(14,j,1,14-j);
    }
  
        
   for(itr=m1.begin();itr!=m1.end();itr++)
    {
        if(itr->first.to_ulong()==1)
        A[itr->first.to_ulong()][0]=0;
        else
        {
            A[itr->first.to_ulong()][0]=LONG_MAX;
        }
        
    }
    for(j=2;j<=n;j++)
    {
        for(itr=m1.begin();itr!=m1.end();itr++)
        {
            if(itr->second==j)
            {
                for(a=1;a<14;a++)
                {
                 if(itr->first[a]==1)
                 {
                     min=A[itr->first.to_ulong()-(long)pow(2,a)][0]+dist(B[0],B[a]);
                     for(d=1;d<n;d++)
                     {
                        if((itr->first[d]==1)&&(d!=a))
                        {
                            if(A[itr->first.to_ulong()-(long)pow(2,a)][d]+dist(B[d],B[a])<min)
                            {
                                min=A[itr->first.to_ulong()-(long)pow(2,a)][d]+dist(B[d],B[a]);
                            }
                        }
                     }
                     A[itr->first.to_ulong()][a]=min;
                 }   
                }
            }
        }
    }  
    min=A[(long)pow(2,14)-1][1]+dist(B[0],B[1]); 
    for(j=2;j<n;j++)
    {
        if(A[(long)pow(2,14)-1][j]+dist(B[j],B[0])<min)
        min=A[(long)pow(2,14)-1][j]+dist(B[j],B[0]);
    } 
    cout<<min;
  

   

}