import sys
import numpy as np
import pprint

def dijkstra(source,w,N):
  d = [np.inf]*N
  visit = [False]*N
  parent = [-1]*N
  parent[source] = source
  d[source] = 0
  for i in range(N):
    a = -1
    b = -1
    mini = np.inf
    for j in range(N):
      if (not visit[j]) and (d[j] < mini):
        a = j
        mini = d[j]
    if a == -1:
      break
    visit[a] = True
    for b in range(N):
      if (not visit[b]) and (d[a] + w[a][b] < d[b]):
        d[b] = d[a] + w[a][b]
        parent[b] = a
  return d

def problem(graph, situation, current, order):
  #pprint.pprint(order)
  if len(order) == 0:
    return 0
  elif situation == 0: # carry no belonging => pick belonging of next order
    destination = order[0][0]
    new_cost = problem(graph,1,destination,order) + graph[current][destination]
  elif situation == 1: # carry one belongings => case 1: go deliver it. case 2: go pick another one
    destination1 = order[0][1] # case 1
    new_cost1 = problem(graph,0,destination1,order[1:]) + graph[current][destination1]
    if len(order) > 1:
      #print order
      destination2 = order[1][0] # case 2
      new_cost2 = problem(graph,2,destination2,order) + graph[current][destination2]
    else:
      new_cost2 = np.inf
    new_cost = min(new_cost1,new_cost2)
  elif situation == 2: # carry two belongings => deliver the first one
    destination = order[0][1]
    new_cost = problem(graph,1,destination,order[1:]) + graph[current][destination]
  else:
    print "QAQ??"
  return new_cost

input_path = sys.argv[1]
f_in = open(input_path,'r')
f_out = open("output.txt","w")

T = int(f_in.readline())
for i in range(T):
  print i
  line = [int(x) for x in f_in.readline().split()]
  N = line[0]
  M = line[1]
  K = line[2]
  w = np.array([[np.inf]*N]*N)
  visit = [False]*N
  for j in range(N):
    w[j][j] = 0
  for j in range(M):
    line = [int(x) for x in f_in.readline().split()]
    #print line
    A = line[0]-1  # remember -1
    B = line[1]-1
    G = line[2]
    w[A][B] = G
    w[B][A] = G
  order = []
  for j in range(K):
    line = [int(x)-1 for x in f_in.readline().split()] # remember -1
    order.append(line)

  graph = []
  for source in range(N):
    d = dijkstra(source,w,N)
    graph.append(d)

  cost = problem(graph, 0, 0, order)
  if cost == np.inf:
    cost = -1
  else:
    cost = int(cost)
  f_out.write("Case #" + str(i+1) + ": " + str(cost) + "\n")

f_in.close()
f_out.close()
 
