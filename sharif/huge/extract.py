import sympy

def inv(x,m):
  return sympy.invert(x,m)

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

def pow_mod(a, b, m):
  s = 1 % m
  count = 0
  while b != 0:
    print count
    if (b%2) == 1:
      s = (s * a) % m
    a = (a * a) % m
    b = b//2
    count = count + 1
  return s

r = 18329600
a = 0x9535fc1b

e = 0x10001

#n = a * 2**r + 1
#a = 27653 * 90527
#27653 * 2 ** ((76395*15+4)*2*4+1)
#90527 * 2 ** ((76351*15+5)*2*4+7)

p_order = ((76351*15+5)*2*4+7)
q_order = ((76395*15+4)*2*4+1)

p = 27653 * 2 ** p_order + 1
q = 90527 * 2 ** q_order + 1
n = p*q

phin = a * 2**r

d = modinv(e,phin)

c = open('enc.raw').read()
cnum = int(c.encode('hex'),16)

tnum = pow(cnum,d,n)
text = hex(tnum).decode('hex')
print text
open('answer.txt','w').write(text)

