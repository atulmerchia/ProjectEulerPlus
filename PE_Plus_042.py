for t in range(int(input())):
    n = float(input())
    n = (2*n + 0.25)**0.5 - 0.5
    if(n - int(n) == 0.0):
        print(int(n))
    else:
        print(-1)
