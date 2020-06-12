# Copyright David Bai: Anyone can use this code without permission or referencing the original source
"""
W1 Kosaraju Algorithm
List Based Iterative Implementation to find sizes of strongly connected components
"""

########################################################
# Data Structures

# node labels range from 1 to 875714. 875715 was used because of the range operator... range(875715) goes up to 875714.
num_nodes = 1000001

# Adjacency representations of the graph and reverse graph
gr = [[] for i in range(2*num_nodes)]
r_gr = [[] for i in range(2*num_nodes)]


# The list index represents the node. If node i is unvisited then visited[i] == False and vice versa
visited = [0] *(2* num_nodes)

# The list below holds info about sccs. The index is the scc leader and the value is the size of the scc.
scc = [0] *(2* num_nodes)
leader = [0] *(2* num_nodes+1)


stack = []  # Stack for DFS
order = []  # The finishing orders after the first pass


########################################################
# Importing the graphs
file = open("2sat6.txt", "r") # I named the input file W1_SCC_edges.txt, but you can name it whatever you wish
data = file.readlines()
i=0
for line in data:
    if i!=0:       
     items = line.split()
     gr[-int(items[0])+num_nodes] += [int(items[1])+num_nodes]
     gr[-int(items[1])+num_nodes] += [int(items[0])+num_nodes]
     r_gr[int(items[0])+num_nodes] += [-int(items[1])+num_nodes]
     r_gr[int(items[1])+num_nodes] += [-int(items[0])+num_nodes]
     
    i=i+1


########################################################
# DFS on reverse graph
f=1
for node in range(2*num_nodes):
  if visited[node]==False: 
   stack.append(node)
   while stack:
        
       
        stack_node=stack.pop()
        if visited[stack_node]!=2:
            stack.append(stack_node)
            if visited[stack_node]==0:
             visited[stack_node]=1
             order.append(stack_node)
            f=1 
            for head in r_gr[stack_node]:
             if visited[head]==0:
                f=0
                visited[head]=1
                stack.append(head)
            if f==1:
             visited[stack_node]=2
             order.append(stack_node)
             stack.pop()



########################################################
# DFS on original graph

visited = [0] * len(visited)  # Resetting the visited variable
order.reverse()  # The nodes should be visited in reverse finishing times

for node in order:
    if visited[node]==0:
        visited[node]=1
        scc[node]=scc[node]+1
        leader[node]=node
        stack.append(node)
        while stack:
           
          stack_node=stack.pop()
          
         
          for head in gr[stack_node]:
            if visited[head]==0:
                visited[head]=1
                scc[node]=scc[node]+1
                leader[head]=node
                stack.append(head)



########################################################
# Getting the five biggest sccs
f=0
for i in range(num_nodes):
    if leader[i]==leader[2*num_nodes-i] and scc[leader[i]]!=1:
        f=1
        break

if f==1:
    print("nah")        

scc.sort(reverse=True)
print(scc[:5])