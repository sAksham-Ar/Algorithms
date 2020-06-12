/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<math.h>

using namespace std;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
cpp_int bpow(cpp_int num,int n)
{
    int i;
    cpp_int f=1;
    for(i=0;i<n;i++)
    f*=num;
    return f;
}
cpp_int kastu(cpp_int num1,cpp_int num2,int n)
{
    if(n<2)
    return num1*num2;
    
    cpp_int a,b,c,d;
    cpp_int ac,bd,abcd;
    a=num1/bpow(10,n/2);
    b=num1%bpow(10,n/2);
      c=num2/bpow(10,n/2);
    d=num2%bpow(10,n/2);
   
    ac=kastu(a,c,n/2);
    bd=kastu(b,d,n/2);
    abcd=kastu(a+b,c+d,n/2)-ac-bd;
    
    return (bpow(10,n))*ac+(bpow(10,n/2))*abcd+bd;
}

int main()
{
    int n=1;
cpp_int a,b,f;
cout<<"enter a:";
cin>>a;
cout<<"enter b:";
cin>>b;

f=a/10;
while(f!=0)
{
n++;
f=f/10;
}

cout<<kastu(a,b,n);

    return 0;
}
