# Kai b01901169

import base64
from pwn import *

count = 0
repeat = 0
threshold = 8
while 1:
  r = remote('csie.ctf.tw',10117)
  s = 'a'*count
  tmp = r.recv()
  r.send('\n')
  tmp = r.recv()
  r.send(s+'\n')

  tmp = r.recv()
  r.close()
  tmp = tmp[0:len(tmp)-2]
  x = base64.b64decode(tmp)
  place = 0
  i = 0
  done = 0
  while i < len(x):
    j = i+repeat
    f = x[j:].find(x[i:j])
    if f>=0:
      repeat = repeat +1
      if f == 0:
        done = 1
        place = i
      i = i-1
    i = i+1
  if (repeat > threshold) & (done == 1):
    print repeat
    break
  print count
  count = count +1
repeat = repeat -1
print 'end searching count: '
print count
print place
#print x[place:place+repeat]
#print x[place+repeat:place+2*repeat]


count = count - 1
#flag = ", flag: "
flag = ""
while 1:
  r = remote('csie.ctf.tw',10117)
  s = 'a'*count
  tmp = r.recv()
  r.send('\n')  
  tmp = r.recv()
  r.send(s+'\n')

  tmp = r.recv()
  tmp = tmp[0:len(tmp)-2]
  x = base64.b64decode(tmp)
  copy = x[place+repeat:place+2*repeat-1]
  r.close()
  # ----- try to fit the string copy ----------

  valid = 0
  for i in range(32,128):
    append = chr(i)
    #print 'gag'
    print i,append
    r = remote('csie.ctf.tw',10117)
    ss = 'a'*count + flag + append
    tmp2 = r.recv()
    r.send('\n')
    tmp2 = r.recv()
    r.send(ss+'\n')

    tmp2 = r.recv()
    tmp2 = tmp2[0:len(tmp2)-2]
    xx = base64.b64decode(tmp2)
    if len(xx) < place + 2*repeat -1:
      break
    copy_test = xx[place+repeat:place+2*repeat-1]
    #print copy
    #print copy_test
    if copy == copy_test:
      valid = 1
      flag = flag + append
      print flag
      break
    r.close()
  
  if valid == 1:
    count = count -1
  else:
    print "not found"
    break

print "end searching with flag: "
print flag
      
  #print base64.b64decode(tmp[1:len(tmp)-1])
