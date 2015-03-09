import math
import time
import os,sys

begin = time.time()
if __name__ == '__main__':
#main >>
    n = 1001; num = n * n; ans = 0; cut = n - 1
    while(num != 1):
        ans += 4 * num - 6 * cut
        num = num - 4 * cut
        cut -= 2
    print (ans + 1)
   
#main <<
end = time.time()
print (end - begin)
