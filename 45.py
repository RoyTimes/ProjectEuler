import math
import time
import os, sys
begin = time.time()

l = [i*(i+1)//2 for i in range (286, 1000001)]
p = [i*(3*i-1)//2 for i in range (166, 1000001)]
sl = set(l); sp = set(p)

n = 144
while True:
    get = n * (2 * n - 1)
    if get in sl and get in sp:
        print (get)
        break
    else: n += 1

end = time.time()
print (end - begin)
