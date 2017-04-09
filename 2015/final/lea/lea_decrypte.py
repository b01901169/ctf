import requests
import hashpumpy

url = 'http://52.68.224.122:9000'


original_data = 'test'
r = requests.get(url+'/sign?data='+original_data)
hexdigest = r.text
data_to_add = 'flag'

for key_length in range(30,50):
  sig,data = hashpumpy.hashpump(hexdigest, original_data, data_to_add, key_length)
  #print data
  r = requests.get(url+'/verify?data='+data+'&sig='+sig)
  print key_length,r.text
  print '\n'



