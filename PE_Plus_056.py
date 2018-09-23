n = int(input())
max = 0

for a in range(n):
    for b in range(n):
        p = a**b
        sum = 0
        while(p > 0):
            sum += p%10
            p //= 10
        if(sum > max):
            max = sum

print(max)
