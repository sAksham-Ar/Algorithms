#include <iostream>
#include <fstream>
using namespace std;
int qs(long int*num,int left,int right)
{
long int count=0,p,i,j,temp,n,mid;
n=right-left+1;
if(left>=right)
return 0;
mid=(right-left)/2;
if((num[left+mid]>min(num[left],num[right]))&&(num[mid+left]<max(num[left],num[right])))
p=mid+left;
else if((num[left]>min(num[left+mid],num[right]))&&(num[left]<max(num[left+mid],num[right])))
p=left;
else
{
    p=right;
}
temp=num[left];
num[left]=num[p];
num[p]=temp;
p=left;
for(i=left+1,j=left+1;j<=right;j++)
{
  if(num[j]<num[p])
  {
    temp=num[i];
    num[i]=num[j];
    num[j]=temp;
    i++;

  }
}
temp=num[i-1];
num[i-1]=num[p];
num[p]=temp;
count+=n-1;
count+=qs(num,left,i-2);
count+=qs(num,i,right);

return count;


}
int main()
{
    long  int a[10000],i,n,f;
    ifstream file("qs.txt");
    for(i=0;i<10000;i++)
    
    file>>a[i];
  
   file.close();
   n=10000;
  
    cout<<qs(a,0,n-1);

}