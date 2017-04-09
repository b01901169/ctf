from pwn import *

dp = 11188888442779478492506783674852186314949555636014740182307607993518479864690065244102864238986781155531033697982611187514703037389481147794554444962262361
dq = 1006725509429627901220283238134032802363853505667837273574181077068133214344166038422298631614477333564791953596600001816371928482096290600710984197710579
dinv = 11196804284042107547423407831525890933636414684075355664222816007929037065463409676450144484947842399975707117057331864113464711778199061912128258484839473

e = 65537

from math import sqrt; from itertools import count,islice

def isPrime(a):
    return all(a % i for i in range(2, a))

def recover_parameters(dp, dq, qinv, e):
    results = []
    d1p = dp * e - 1
    for k in range(3, e):
        if d1p % k == 0:
            hp = d1p // k
            p = hp + 1
            if isPrime(p):
                d1q = dq * e - 1
                for m in range(3, e):
                    if d1q % m == 0:
                        hq = d1q // m
                        q = hq + 1
                        if isPrime(q):
                            if (qinv * q) % p == 1 or (qinv * p) % q == 1:
                                results.append((p, q, e))
                                print(p, q, e)
    return results

def egcd(a, b):
    u, u1 = 1, 0
    v, v1 = 0, 1
    while b:
        q = a // b
        u, u1 = u1, u - q * u1
        v, v1 = v1, v - q * v1
        a, b = b, a - q * b
    return u


def get_d(p, n, e):
    q = n / p
    phi = (p - 1) * (q - 1)
    d = egcd(e, phi)
    if d < 0:
        d += phi
    return d


with open("flag.enc", "rb") as input_file:
    n = p * q
    data = input_file.read()
    ct = bytes_to_long(data)
    d = get_d(p, n, e)
    pt = pow(ct, d, n)
    print("pt: " + long_to_bytes(pt))

