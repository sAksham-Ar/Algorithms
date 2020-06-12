#include<bits/stdc++.h>
using namespace std;
long long A[1001]={0};
class symbol
{
    vector<int> no;
    long long weight;
    public:
    symbol()
    {
        weight=0;
    }
    symbol(vector<int> n,long long w)
    {
        no=n;
        weight=w;
    }
    long long getw() const{
        return weight;
    }
    vector<int> getn()
    {
        return no;
    }
};
class myComparator 
{ 
public: 
    int operator() (const symbol& p1, const symbol& p2) 
    { 
        return p1.getw() > p2.getw(); 
    } 
}; 
priority_queue <symbol, vector<symbol>, myComparator > pq; 
int main()
{
    symbol f,g;
 int n,i=1;
 vector<int> no;
 long long w;
 ifstream file("huffman.txt");
 file>>n;
 while(file>>w)
  {
      no.push_back(i);
      pq.push(symbol(no,w));
      i++;
      no.clear();
  }
  vector<int> n1;
  while(pq.size()>1)
  {
  f=pq.top();
  pq.pop();
  g=pq.top();
  pq.pop();
  n1=f.getn();
 for (int j=0;j<g.getn().size();j++)
 n1.push_back(g.getn()[j]);
  for(int j=0;j<n1.size();j++)
  A[n1[j]]+=1;
  pq.push(symbol(n1,f.getw()+g.getw()));
  n1.clear();
 
  
}
sort(A+1,A+n+1);

cout<<A[1]<<' '<<A[n];

}