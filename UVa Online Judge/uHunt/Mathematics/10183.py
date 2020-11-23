f = list()
f.append(1)
f.append(2)
x = 1
for i in range(483):
    f.append(f[x] + f[x-1])
    x += 1
while True:
    _in = input().split()
    if _in[0] == "0" and _in[1] == "0":
        break
    ini = 0
    res = 0
    a = int(_in[0])
    b = int(_in[1])
    for i in range(485):
        if f[i] >= a:
            ini = i
            break
    for i in range(ini, 485, 1):
        if f[i] > b:
            break
        res += 1
    print(res)
