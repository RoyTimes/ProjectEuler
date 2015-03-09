n = 1000000
a = [0 for i in range (n + 1)];

i = 2
while i <= n:
    if  (a[i] == 0):
        j = i << 1;
        while (j < n):
            a[j] = a[j] + 1
            j += i
    i += 1
for i in range (1, n + 1- 3):
    if (a[i] == 4 and a[i + 1] == 4 and a[i + 2] == 4 and a[i + 3] == 4):
        print (i)
        break
        
