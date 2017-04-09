import sympy

def inv(x, m):
  return sympy.invert(x, m)

def pow_mod(a, b, m):
  s = 1 % m
  while b != 0:
    if (b%2) == 1:
      s = (s * a) % m
    a = (a * a) % m
    b = b//2
  return s

p = 244568058927274035851630625490731151685151358429;
q = 282282802054792109028071238910250727429434271943;
n = p*q;
e = 65537;
phi_n = (p-1)*(q-1);
d = int(inv(e,phi_n));
c = 56267348817991667025293700596381772772705100752049364933949564121901533557055297556368355657861;
m = pow_mod(c,d,n);
# message = ''.join();
print hex(m)[2:-1].decode("hex");
