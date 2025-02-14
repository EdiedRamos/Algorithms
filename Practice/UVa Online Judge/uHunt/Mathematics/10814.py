from math import gcd
t = int(input())
while t:
    a, b = map(int, input().split('/'))
    g = gcd(a, b)
    a //= g
    b //= g
    print(a, b, sep=' / ')
    t -= 1
