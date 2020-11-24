tc = 1
while True:
    n = int(input())
    if n == 0:
        break
    print("Case ", tc, ": ", n >> 1, sep="")
    tc += 1
