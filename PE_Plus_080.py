from decimal import *

n = int(input())
p = int(input())

getcontext().prec = p + 33

n = n + 1
p = p + 1

ans = 0

for i in range(1, n):
    rt = int(i ** 0.5)
    if rt * rt == i:
        continue
    root = str(Decimal(i).sqrt())
    count = False
    for c in root[:p]:
        if c != '.':
            ans += int(c)

print(ans)
