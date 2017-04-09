# Team: q86
# member: Kai ru286 scrashedward pml0415 duolc

from pwn import *
import sympy

def inv(x,m):
  return sympy.invert(x,m)

r = remote('csie.ctf.tw',10120)
for i in range(1,12,1):
  tmp = r.recvline()
  tmp = r.recvline()
  n = int(tmp[:-1])
  tmp = r.recvline()
  m3 = int(tmp[:-1])
  tmp = r.recvline()
  mplus3 = int(tmp[:-1])
  
  m2_m = (mplus3 - m3 -1) % n
  #m2_m = (m2_m * inv(3,n)) % n
  if m2_m % 3 == 0:
    m2_m /= 3
  elif m2_m % 3 == 1:
    m2_m = m2_m + n * (3 - n%3)
    m2_m /= 3
  else:
    m2_m = m2_m + n * (n%3)
    m2_m /= 3

  m2_m = m2_m % n
  
  t = (pow(m2_m,2) - m2_m - 2*m3 + 3*n) % n
  m = (t * inv(m3-1,n)) % n
  if i==11:
    # print int(m)
    p = format(int(m),'x')
    # print p
    ans = p.decode('hex')
    print ans[:49]
  r.send(str(m)+'\n')
r.close()
