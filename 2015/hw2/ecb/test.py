import base64
from pwn import *

count = 127
flag = ""
repeat = 16
place = 37
while 1:
  r = remote('csie.ctf.tw',10117)
  mycount = raw_input('>>> input count: ')
  string = raw_input('>>> string: ')
  s = 'a'*int(mycount) + flag + string
  tmp = r.recv()
  r.send('\n')
  tmp = r.recv()
  r.send(s+'\n')

  tmp = r.recv()
  tmp = tmp[0:len(tmp)-2]
  x = base64.b64decode(tmp)
  print x[place+repeat:place+2*repeat]
  #place = x.find(rs)
  #copy = tmp[place+length:place+2*length]
  #print copy
  r.close()
  # ----- try to fit the strini
