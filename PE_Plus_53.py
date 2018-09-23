def countVariance(prod, numer, d1, d2, k):
    while(prod > k):
        d1 += 1
        prod = prod * d2 / d1
        d2 -= 1
    return d1 - d2 - 1

n, k = [int(x) for x in input().split()]

numer = 1
d1 = 0
d2 = 1
prod = 1
sum = 0

while(numer < n):
    numer += 1
    if(numer % 2 == 0):
        d1 += 1
        prod = prod * numer // d1
    else:
        d2 += 1
        prod = prod * numer // d2
    if(prod > k):
        sum += countVariance(prod, numer, d1, d2, k)

print(sum)

 # Find the minimum nCr (maximized @ r = n/2 ish)
 # For each n between n_min & n_max, find how many deviations you can take
 # Multiply deviations by two, subtract 1 if n%2 == 0
 # Print total
