#!/usr/bin/env python3

# Hint: Flag starts with "SharifCTF{", and ends with "}".

from secret import p_small_prime, q_small_prime, r, key, flag
flag = flag * r

def encrypt(msg, p, q, r, key):
	enc = []
	for i in range(len(msg)):
		enc += [(i%p) ^ ((msg[i]**q) % (q**2 - 6*q + 6)) ^ key[r*i % len(key)]]
	return bytes(enc)

with open('enc', 'wb') as f:
	f.write(encrypt(flag, p_small_prime, q_small_prime, r, key))
