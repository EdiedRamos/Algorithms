// * 3679. Minimum Discards to Balance Inventory

function minArrivalsToDiscard(
  arrivals: number[],
  w: number,
  m: number
): number {
  let discarded = 0,
    left = 0,
    right = 0
  const taken = new Set<number>()
  const frecuency: Record<number, number> = {}
  for (; right < arrivals.length; right++) {
    if (right - left + 1 > w) {
      if (taken.has(left)) {
        frecuency[arrivals[left]]--
      }
      left++
    }
    const currentFrecuency = frecuency[arrivals[right]] ?? 0
    if (currentFrecuency + 1 > m) {
      discarded++
    } else {
      taken.add(right)
      frecuency[arrivals[right]] = currentFrecuency + 1
    }
  }
  return discarded
}
