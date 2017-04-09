# b01901169 kai

import signal
import sys
import os
import time
import base64
import random
from Crypto.Cipher import AES
from Crypto.Hash import SHA256

from pwn import *

BS = 16
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS)
unpad = lambda s: s[:-ord(s[-1])]

class MyAES:
    def __init__(self, key):
        self.key = key
        self.iv = 'This is an IVIVI'

    def encrypt(self, raw):
        message = pad(raw)
        aes = AES.new(self.key, AES.MODE_CBC, self.iv)
        return base64.b64encode(aes.encrypt(message))

    def decrypt(self, enc):
        cipher = base64.b64decode(enc)
        aes = AES.new(self.key, AES.MODE_CBC, self.iv)
        return unpad(aes.decrypt(cipher))

r = remote('csie.ctf.tw',10121)
r.recvline()
r.recvline()
ID = 'admin'
password = 'meowmeowmeowmeow'
N = '12'
message = ID + '||' + N
sha256 = SHA256.new()
sha256.update(message)
digest = base64.b64encode(sha256.digest())
r.send(message + '||' + digest + '\n')
r.recv(100)
Ns_cipher = r.recvline()
Ns,cipher,second_digest = Ns_cipher.split('||')
# use cipher to guest password here
# -------------------------------------------
# second time connect to get cipher of ID+'||'+Ns
# TODO
r2 = remote('csie.ctf.tw',10121)
r2.recvline()
r2.recvline()
ID = 'admin'
message2 = ID + '||' + Ns
sha256_2 = SHA256.new()
sha256_2.update(message2)
digest2 = base64.b64encode(sha256_2.digest())
r2.send(message2 + '||' + digest2 + '\n')
r2.recv(100)
extract_cipher = r2.recvline()
Ns2,cipher2,junk = extract_cipher.split('||')
r2.close()
# -------------------------------------------
#aes = MyAES(password)
#third_cipher = aes.encrypt(ID + '||' + Ns)
sha256 = SHA256.new()
sha256.update(cipher2)
third_digest = base64.b64encode(sha256.digest())
r.send(cipher2 + '||' + third_digest + '\n')
r.recvline()
print r.recvline()
r.close()
