while True:
  try:
    m = input()
    n = int(m)
    s = n ** 2
    s = str(s)
    s = s[len(s) - len(str(m)) :]
    if s == str(m) and n != 0 and n != 1:
      print(f'Automorphic number of {len(m)}-digit.')
    else:
      print('Not an Automorphic number.')
  except EOFError:
    break