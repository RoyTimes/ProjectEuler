import math
import time
import os,sys

if __name__ == "__main__":
#main >>>
    b = set()
    for i in range(2, 101):
        for j in range(2, 101):
            b.add(i ** j)
    print (len(b))
#main <<<
