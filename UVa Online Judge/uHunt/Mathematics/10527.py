# coder: Yeshayah

n = int(input())

while n != -1:
  if n == 0:
    print("10")
    n = int(input())
    continue
  digits = []
  can = True
  if n < 10:
    digits.append(1)
  while n > 9 and can:
    can = False
    for i in range(9, 1, -1):
      if n % i == 0:
        digits.append(i)
        can = True
        n //= i
        break
  digits.append(n)
  digits.sort()
  if can:
    for i in digits:
      print(i, end='')
    print()
  else:
    print("There is no such number.")
  n = int(input())