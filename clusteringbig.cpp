#include<bits/stdc++.h>
using namespace std;
long long A[200001];
long long  B[200001];
long long k=200000;
long long cnt=0;
struct Comparer {
    bool operator() (const bitset<24> &b1, const bitset<24> &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};
void un(long long  s,long long  d)
{
  long long s1=A[s],d1=A[d];
   if(B[A[s]]>=B[A[d]])
   {
       for(long long  i=1;i<=k;i++)
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
     for(long long  i=1;i<=k;i++)
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
      

unordered_map <bitset<24> , int> mymap;
pair <bitset<24> , int> p;
void cluster()
{
    long long i,j;
    bitset<24> b;
    unordered_map <bitset<24> , int>::iterator itr,itr2;

    for(i=1;i<=k;i++)
    {
        A[i]=i;
    }
     for(i=1;i<=k;i++)
    {
        B[i]=1;
    }

    for(itr=mymap.begin();itr!=mymap.end();++itr)
    {
     
        b=itr->first;
       for(i=0;i<24;i++)
       {
          
           b.flip(i);
           itr2=mymap.find(b);
           if(itr2!=mymap.end())
           {
               if(A[itr->second]!=A[itr2->second])
               {
                  
                   un(itr->second,itr2->second);
               } 
           }
           b.flip(i);

       }
    for(i=0;i<24;i++)
       {
        for(j=0;j<24;j++)
        {  
            if(i!=j)
            {
           b.flip(i);
           b.flip(j);
           itr2=mymap.find(b);
           if(itr2!=mymap.end())
           {
               if(A[itr->second]!=A[itr2->second])
               {
                   un(itr->second,itr2->second);
               } 
           }
           b.flip(i);
           b.flip(j);
            }
        }
       }
       b.reset();
    

    }
    cout<<(k-count(B+1,B+k,0))-cnt;
}
int main()
{
    int m;
    long long n,i=1,max=-1;
   
    ifstream file("clb.txt");
    string str;
    getline(file,str);
    stringstream ss(str);
    ss>>n>>m;
    k=n;
    while(getline(file,str))
    {
        str.erase(remove(str.begin(),str.end(),' '),str.end());
       p.first=bitset<24>(string(str));
       
       p.second=i;
       if(mymap.find(p.first)==mymap.end())
       {
       mymap.insert(p);
       
       }
       else
       {
           cnt++;
       }
       
       i++;
    }
 
 
  
   cluster();
    return 0;
    
}