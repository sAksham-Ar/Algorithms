import math 
n=10000
hash1=[0]*(2*n+1)
A=[]
count=0

file = open("sum.txt", "r") # I named the input file W1_SCC_edges.txt, but you can name it whatever you wish
data = file.readlines()

for line in data:
    items = line.split()
    A.append(int(items[0]))
    
A.sort()
i=0
j=len(A)-1
b=[]
f=0
k=0
while i<=j:
    if A[i]+A[j]<-10000:
        i=i+1
    elif A[i]+A[j]>10000:
        j=j-1
    else:

        for k in range(i,j):
            
             if A[j]+A[k]<=10000 and A[j]+A[k]>=-10000 :
                 hash1[A[j]+A[k]+n]=1
            
   
             elif A[j]+A[k]>10000:
               break
        i=i+1 
    
for i in range(0,2*n+1):
    if hash1[i]==1:
        count=count+1
             
print(count)