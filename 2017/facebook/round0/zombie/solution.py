import numpy as np
import sys

input_name = sys.argv[1]
f_in = open(input_name,'r')
f_out = open("output","w")

T = int(f_in.readline())

for i1 in range(T):
  line = f_in.readline().split()
  H = int(line[0])
  S = int(line[1])
  line = f_in.readline().split()
  assert(len(line) == S)
  prob_list = []
  for i2 in range(S):
    order = line[i2]
    tmp_H = H
    if "-" in order:
      tmp = order.split('-')
      order = tmp[0]
      tmp_H += int(tmp[1])
    elif "+" in order:
      tmp = order.split('+')
      order = tmp[0]
      tmp_H -= int(tmp[1])
    tmp = order.split('d')
    X = int(tmp[0])
    Y = int(tmp[1])
    #print X,Y,tmp_H
    result = [1]
    for i3 in range(X):
      a = np.ones(Y)
      result = np.convolve(result,a)
    result /= result.sum()
    #print result
    if tmp_H-X < 0:
      prob = 1
    elif tmp_H-X >= len(result):
      prob = 0
    else:
      prob = sum(result[tmp_H - X:])
    prob_list.append(prob)
  max_prob = max(prob_list)
  f_out.write("Case #" + str(i1+1) + ": " + str(max_prob) + "\n")

f_in.close()
f_out.close()


