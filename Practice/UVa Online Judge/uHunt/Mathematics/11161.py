#coder: Yeshayah

fibo = [0, 1, 1]
first = [0, 0, 1]

for i in range(3, 1501):
  fibo.append(fibo[i - 1] + fibo[i - 2])
  first.append(first[i - 1] + fibo[i - 1])

it = 1

while True:
  n = int(input())
  if n == 0: break
  size = fibo[n]
  if size & 1: size += 1
  size >>= 1
  print("Set ", it, ":", sep="")
  print(first[n] + size - 1)
  it += 1
