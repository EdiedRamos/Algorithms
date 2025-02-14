cat = [1]

for i in range(1, 1001):
  cat.append(((2 * i * (2 * i - 1)) * cat[i - 1]) // ((i + 1) * i))

while True:
  try:
    n = int(input())
    print(cat[n])
  except EOFError:
    break