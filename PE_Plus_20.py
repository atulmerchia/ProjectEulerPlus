from math import factorial
from math import floor

for t in range(int(input())):
    prod = factorial(int(input()))
    sum = 0;

    while(prod > 0):
        sum += prod % 10
        prod = prod//10
    print(sum)
