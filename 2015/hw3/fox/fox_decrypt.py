from pwn import *

while 1:
  r = remote('csie.ctf.tw',10122)
  r.send('fox||945\n')
  m = r.recvline()
  a,b = m.split('||')
  b = int(b[:-1])
  print b
  if b == 213:
    r.send('YMkKN9rbkiPVctYOo2KZxsZSl0HcfrPmyYx/lRtvq5c=\n')
    r.recvline()
    print r.recvline()
    break
  r.close()

