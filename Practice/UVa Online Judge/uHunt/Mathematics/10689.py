def sequence(a, b, n):
  c = a + b
  for i in range(n):
    a = b
    b = c
    c = a + b
  return a
t = int(input())
opt = {1 : 60, 2 : 300, 3 : 1500, 4 : 15000}
for it in range(t):
  # a, b, n, m = map(int, input().split())
  t = input().split()
  a = int(t[0])
  b = int(t[1])
  n = int(t[2])
  m = int(t[3])
  if n > opt[m]:
    n -= opt[m] * (n // opt[m])
  sq = str(sequence(a, b, n))
  if len(sq) <= m:
    print(sq)
  else:
    print(int(sq[len(sq) - m:]))