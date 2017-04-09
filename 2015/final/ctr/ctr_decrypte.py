# name: kai
# team: q86
# problem: CTR

import base64

s = 'lIFvjm+11WvGkgAtM0DiXY5HC1ToeNjt6nmLVqvx' # user=123
# t = 'lIFvjm+11WvGkgAtM0DiXY5HH0PgY5T18jzLEOzx' # for test
ds = base64.b64decode(s)
# dt = base64.b64decode(t) # for test
dds = ds[16:]
# ddt = dt[16:]

user123 = '{\"user\":\"123\"}'
target = '{\"admin\":true}'

# tmp1 = [ord(a) ^ ord(b) for a,b in zip(dds,ddt)]
# tmp2 = [ord(a) ^ ord(b) for a,b in zip(target,user123)]

l = ''.join(chr(ord(a) ^ ord(b) ^ ord(c)) for a,b,c in zip(dds,user123,target))

out_s = (ds[:16] + l)
output = base64.b64encode(out_s)

# send 52.68.224.122:9010/admin?token=output
# this output = 'sxB0KG8Pjk5V9ItyLvNVENJ7yzYg0GXBDP96xlyu'
