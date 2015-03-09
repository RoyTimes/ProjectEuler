import math
import time
import os, sys

def get_sum (x):
    sum = 0
    for ch in enumerate(x):
       sum += int(ch[1]) ** 5
    return sum

tot = 0
for i in range (2, 1000000):
    if get_sum(str(i)) == i:
        tot += i

print (tot)
