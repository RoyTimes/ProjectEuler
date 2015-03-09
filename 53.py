import math

if __name__ == "__main__":
#Main >>
    ans = 0
    for n in range (23, 101):
        d = n
        r = 1
        while d < 1000000 and r <= int(n / 2):
            d = d * (n - r) / (r + 1)
            r += 1
        ans += n - 2 * r + 1
    print (ans)

#Main <<
