# Packing gifts for santa

def pack_gifts(gifts: list[int], maxWeight: int) -> int | None:
  sleigts = 1 if gifts else 0
  currentWeight = 0
  for gift in gifts:
    if gift > maxWeight:
      return None
    if currentWeight + gift > maxWeight:
      sleigts += 1
      currentWeight = gift
    else:
      currentWeight += gift
  return sleigts

print(pack_gifts([2, 3, 4, 1], 5))
print(pack_gifts([1, 1, 1, 1], 2))
print(pack_gifts([5, 6, 1], 5))
print(pack_gifts([], 10))
print(pack_gifts([3, 3, 2, 1], 3))
