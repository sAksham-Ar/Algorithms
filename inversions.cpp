#include <iostream>
#include <fstream>
using namespace std;

long long int sc(long long int* arr,long long int* d,long int left,long long int right)
{
    long long int x=0,y=0,z=0,i,k,m,j,f;
   
    if(right>left)
    {
    k=(left+right)/2;
    
    x+=sc(arr,d,left,k);
    
    y+=sc(arr,d,k+1,right);
  
    i=left;
    j=k+1;
    f=left;
   while((i<=k)&&(j<=right))
    {  
        if(arr[i]<arr[j])
        {
          d[f]=arr[i];
          i++;
          f++;
        }
        else if(arr[j]<arr[i])
        {
            d[f]=arr[j];
            z+=k+1-i;
            j++;
            f++;
        }


    } 
    
    for(;i<=k;i++,f++)
    {
     d[f]=arr[i];
    }
    
    for(;j<=right;j++,f++)
    {
        d[f]=arr[j];
    }
        for (i = left; i <= right; i++) 
        arr[i] = d[i]; 

    }

    return x+y+z;
     
  
}
int main()
{
    long long int a[100000],i,n,d[100000];
    ifstream file("int.txt");
    for(i=0;i<100000;i++)

    file>>a[i];
    
   file.close();
   n=100000;

    cout<<sc(a,d,0,n-1);
}