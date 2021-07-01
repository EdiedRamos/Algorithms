# coder: Yeshayah
# This problem is about catalan numbers and about factorials

cat = []
fact = []

cat.append(1)
fact.append(1)

for i in range(1, 302):
  fact.append(i * fact[i - 1])

for i in range(1, 302):
  cat.append(((2 * i * (2 * i - 1)) * cat[i - 1]) // ((i + 1) * i))

n = int(input())

while n != 0:
  print(cat[n] * fact[n])
  n = int(input())
