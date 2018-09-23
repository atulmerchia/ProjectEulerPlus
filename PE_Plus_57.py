import math

n = int(input())

num = 3
den = 2

for i in range(2, n+1):
    temp = den
    den = den + num
    num = den + temp
    if(int(math.log10(num)) > int(math.log10(den))):
        print(i)
