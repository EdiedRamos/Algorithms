#coder: Yeshayah

fib = [1, 2]

for i in range(2, 1001):
  fib.append(fib[i - 1] + fib[i - 2])

while True:
  try:
    print(fib[int(input())])
  except EOFError:
    break
