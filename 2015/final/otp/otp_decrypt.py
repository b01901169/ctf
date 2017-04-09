from subprocess import call
import os

otpin = 'input.txt'
otpout = 'output.txt'
maxcount = 255
f = open('flag.png.encrypted','r')
tmp = f.read()
target = tmp[0:8]
png = chr(137)+chr(80)+chr(78)+chr(71)+chr(13)+chr(10)+chr(26)+chr(10)
f.close()
f1 = open(otpin,'w')
f1.write(png)
f1.close()

key = 68
out = 0
step_size = 256
c = 0
while 1:
  count = 0
  record = [0,0]
  call(['./otp',str(key),otpin,otpout], stdout = open(os.devnull, 'wb'))
  f2 = open(otpout,'r')
  sget = f2.read()
  f2.close()
  for i in range(0,len(target)):
    if sget[i] == target[i]:
      count = count + 1
      if count > c:
        c = count
        print 'c increase to: ',c ,' with key = ',key
  if count > 5:
    print 'get key= ',key
  if count == 8:
    break
  key = (key + step_size) % (1<<32)
  if key > out:
    print 'tmp: key = ',key
    out = out + 10000000
print 'complete search', key

