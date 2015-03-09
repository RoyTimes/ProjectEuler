import math
import os,sys
import time


begin = time.time()
if __name__ == "__main__":
#main >>

    solved = False
    getlist = set()
    i = 0
    
    while solved != True:
        i += 1
        get = int (i * (3 * i - 1) / 2)
        getlist.add(get)
        for num in getlist:
            if get - num in getlist and get - num * 2 in getlist:
                print (abs(num - (get - num)))
                solved = True    
   
#main <<
end = time.time()
print (end - begin)
