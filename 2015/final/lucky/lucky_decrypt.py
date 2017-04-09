from hashlib import sha1
from random import random

a = 'da7bfc72'
s = a.decode('hex')
target = '000000.'

SIZE = 2<<30

for i in xrange(1,SIZE):
  rand = `random()`
  h = sha1(a+rand).hexdigest()
  if h[0:7] == target:
    print 'collision!!',rand
    break
  
