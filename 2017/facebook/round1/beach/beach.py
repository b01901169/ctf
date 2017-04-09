import sys
import numpy as np
import pprint

input_path = sys.argv[1]
f_in = open(input_path,'r')
f_out = open("output.txt","w")

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        return -1
    else:
        return x % m

def factorial(n,modular):
  a = 1
  factor = []
  for i in range(n):
    factor.append(a)
    a = (a*(i+1)) % modular
  return a,factor

T = int(f_in.readline())
modular = 1000000007

def combination(n,r,factor,modular):
  a = (factor[n] * modinv(factor[n-r],modular) * modinv(factor[r],modular)) % modular
  return a

print "compute factor"
a,factor = factorial(100000000,modular)
print "finish factor"

for i in range(T):
  print "problem:",i
  line = [int(x) for x in f_in.readline().split()]
  N = line[0]
  M = line[1]
  radius = []
  for j in range(N):
    radius.append(int(f_in.readline()))
  radius_sum = sum(radius)
  if N == 1:
    total = M
  elif N == 0:
    total = 1
  else:
    total = 0
    for j in range(N):
      for k in range(N):
        if j==k:
          continue
        s = radius_sum*2 - radius[j] - radius[k]
        #print s, M
        if s > M-1:
          increase = 0
        else:
          #print "factorial:"
          #print factorial(N+M-s,modular)
          #print factorial(M-s,modular)
          increase = (factor[N-2] * combination(M-1-s+N,N,factor,modular)) % modular 
          #print "increase:",increase
        total += increase
  total = total % modular
  f_out.write("Case #" + str(i+1) + ": " + str(total) + "\n")

f_in.close()
f_out.close()
                    
