import numpy as np
import sys

input_name = sys.argv[1]
f_in = open(input_name,"r")
f_out = open("output",'w')
inputs = f_in.readlines()
f_in.close()
number = int(inputs[0])
center = (50,50)
radius = 50

for i in range(number):
  line = inputs[i+1].split()
  progress = float(line[0])
  degree = progress/100 *360
  print degree
  x = float(line[1]) - center[0]
  y = float(line[2]) - center[1]
  tan = float(y)/x
  degree2 = -np.arctan(tan)/ np.pi * 180
  if x < 0:
    degree2 = degree2 + 180
  degree2 = 90 + degree2
  print degree2
  if np.sqrt(x*x+y*y) > radius: 
    f_out.write("Case #" + str(i+1) + ": white\n")
  elif degree2 > degree:
    f_out.write("Case #" + str(i+1) + ": white\n")
  else:
    f_out.write("Case #" + str(i+1) + ": black\n")

f_out.close()
