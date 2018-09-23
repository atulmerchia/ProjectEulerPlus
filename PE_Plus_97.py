t = int(raw_input())
mod = 1000000000000
sum = 0;

def powmod(b, e):
    res = 1
    copy = b
    while(e != 0):
        if(e & 1):
            res = res * copy % mod

        copy = copy * copy % mod
        e //= 2

    return res

known = dict()

for i in range(t):
    a, b, c, d = [int(j) for j in raw_input().split()]
    sum += d;

    res = 0
    if (b, c) in known:
        res = known[(b,c)]
    else:
        res = powmod(b, c)
        known[(b,c)] = res

    sum = (sum + a * res % mod) % mod;

print("%012d" % sum)
