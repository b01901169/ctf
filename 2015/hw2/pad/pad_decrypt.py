# Kai b01901169

from pwn import *
import base64

def ask(inverse_set,s,r):
  tmp = ''.join(chr(x) for x in inverse_set)
  r.send(base64.b64encode(tmp+s)+'\n')
  tmp = r.recvline()
  if tmp[0:5] == 'false':
    return 0
  else:
    return 1


text = 'NfHBHcVs1MzChTWg/yPibl97EcV9e566VfocKI60xhOVG/ko1PVQ2g9F5etdzLiAwPhczk8zPqJ99ohkKWehVg=='
s = base64.b64decode(text)
length = len(s)
blocksize = 16
flag = ""
r = remote('csie.ctf.tw',10118)
for i in range(length/blocksize-1,-1,-1):
  j = 0
  blocks = s[i*blocksize:(i+1)*blocksize]
  inverse_set = [0]*blocksize
  while j < blocksize:
    for k in range(256):
      count = 0
      inverse_set[blocksize - j -1] = k
      t = ask(inverse_set,blocks,r)
      if (j == 0) & (t == 1):
        tmp_inverse_set = inverse_set
        tmp_inverse_set[blocksize - 2] = inverse_set[blocksize -2] ^ 1
        t2 = ask(tmp_inverse_set,blocks,r)
        if t2 == 1:
          flag += chr(k ^ (j+1))
          break
      elif t == 1:
        flag += chr(k ^ (j+1))
        break
    #inverse_set = [x ^ (j+1) ^ (j+2) for x in inverse_set]
    for l in range(j+1):
      inverse_set[blocksize - l -1] = inverse_set[blocksize - l -1] ^ (j+1) ^ (j+2)
    j += 1

r.close() 
flag = flag[::-1]
test = [ord(xxx) for xxx in flag]
stest = [ord(xxx) for xxx in s]
true_flag = ''.join([chr(xxx[0]^xxx[1]) for xxx in zip(test[16:64],stest[0:48])])
print true_flag
