import requests
import hashlib
import hashpumpy

url = 'http://52.68.224.122:9000'
blocksize = 64
ipad = chr(0x36)*blocksize
opad = chr(0x5c)*blocksize
ichar = chr(0x36)

r = requests.get(url+'/sign',params={'data': ipad,'deprecated': True})
ipad_h = r.text
data = 'flag'
key_length = 63;

sig1,data1 = hashpumpy.hashpump(ipad_h, ichar, data, key_length)
sig_input = ''.join(chr(int(sig1[i:i+2],16)) for i in range(0,len(sig1),2))

r = requests.get(url+'/sign',params={'data': opad+sig_input,'deprecated': True})
sig = r.text

r = requests.get(url+'/verify',params={'sig': sig, 'data': data1[1:]})
print r.text


