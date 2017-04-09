import sys
import numpy as np

input_path = sys.argv[1]
f_in = open(input_path,'r')
f_out = open("output.txt","w")

T = int(f_in.readline())
for i in range(T):
  line = [int(x) for x in f_in.readline().split()]
  N = line[0]
  M = line[1]
  price = []
  for j in range(N):
    line = sorted([int(x) for x in f_in.readline().split()])
    for k in range(M):
      price.append(line[k] + k*2 + 1)
  sort_price = sorted(price)
  cost = sum(sort_price[:N])
  f_out.write("Case #" + str(i+1) + ": " + str(cost) + '\n')

f_in.close()
f_out.close()
