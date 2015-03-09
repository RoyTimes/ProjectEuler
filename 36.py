import math
import os,sys
import time

def Change(n):
	bin = []
	if(n <= 0): return [0]
	while(int(n) != 0):
		bin.append(str(int(n) % 2))
		n = int(n)/ 2
		print (n)
	bin.reverse()
	s = ''.join(bin)
	return s

def Judge(n):
	dec = str(n)
	re_d = dec[::-1]
	bin = Change(n)
	re_b = bin[::-1]
	return (dec == re_d and bin == re_b);

if __name__ == "__main__":
        sum = 0
        for i in range (1, 1000000):
                if(Judge(i)):
                        sum += i
        print (sum)
