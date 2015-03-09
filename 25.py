import math

if __name__ == "__main__":
#main <<
    a, b, c = 1, 1, 0
    cut = 2
    while(1):
        c = a + b; cut += 1
        if len(str(c)) >= 1000: break;
        a = b; b = c
    print (cut)
#main >>
