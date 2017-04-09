import sys
import numpy as np

input_name = sys.argv[1]
f_in = open(input_name,'r')
f_out = open("output","w")
total_weight = 50

T = int(f_in.readline())
for i1 in range(T):
  N = int(f_in.readline())
  W = []
  for i2 in range(N):
    W.append(int(f_in.readline()))
  W = sorted(W)
  print W
  last = len(W)-1
  first = 0
  count = 0
  while 1:
    max_w = W[last]
    min_number = np.ceil(total_weight/float(max_w))
    first += min_number - 1
    if first > last:
      break
    last -= 1
    count += 1
  f_out.write("Case #" + str(i1+1) + ": " + str(count) + "\n")

f_in.close()
f_out.close()
