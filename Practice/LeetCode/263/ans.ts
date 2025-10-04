// * 263. Ugly Number

function isUgly(x: number): boolean {
  if (x === 0) return false
  for (const j of [2, 3, 5]) {
    while (x % j === 0) {
      x /= j
    }
  }
  return x === 1
}
