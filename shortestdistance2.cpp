#include<bits/stdc++.h>
using namespace std;
int n=201;
long int A[201];
bool B[201]={false};
class edge
{

    int dest,src;
    long int len;
    public:
    edge(int s,int d,long int l)
    {
        src=s;
        dest=d;
        len=l;
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
               
            
           if(B[f.getd()]==true)
           {
               l=A[f.gets()]+f.getl();
               if(l<A[f.getd()])
               {
               A[f.getd()]=l;
                for(i=0;i<v[f.getd()].size();i++)
            {
                 pq.push(v[f.getd()][i]);
                
            }
           }
           }
           else
           {
            A[f.getd()]=A[f.gets()]+f.getl();
            B[f.getd()]=true;
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
 int s,d,i=0;
 char c;
 long int l;
   vector<edge> v[201];
   string instruction,temp;
    ifstream file("sd.txt");
  if (file.is_open()){
    cout << "test" << endl;
    //Read until no more lines in text file to read
    while (getline(file, instruction))
    {

        istringstream ss(instruction);
        string token;
        ss>>temp;
        stringstream(temp)>>s;
        temp="";
        //cout<<s<<' ';
        while(!ss.eof())
        {
          ss>>temp;
          //cout<<temp<<" ";
          stringstream(temp)>>d>>c>>l;
       //cout<<d<<','<<l<<" ";
          v[s].push_back(edge(s,d,l));
          temp="";
        }
       // cout<<endl;
         instruction="";
    ss.clear();//clear any bits set
    ss.str(std::string());

    }
   
}

sd(v);
cout<<A[7]<<','<<A[37]<<','<<A[59]<<','<<A[82]<<','<<A[99]<<','<<A[115]<<','<<A[133]<<','<<A[165]<<','<<A[188]<<','<<A[197];

