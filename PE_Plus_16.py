for i in range(int(input())):
    num = 2**int(input())
    total = 0
    for x in str(num):
        total += int(x)
    print(total)
