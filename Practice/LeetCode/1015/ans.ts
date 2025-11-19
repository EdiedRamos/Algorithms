// * 1015. Smallest Integer Divisible by K

function smallestRepunitDivByK(k: number): number {
  let count = 1
  let val = 1
  const taken: Record<number, boolean> = {}
  while (val % k !== 0) {
    val = (val * 10 + 1) % k
    if (taken[val]) return -1
    taken[val] = true
    count++
  }
  return count
}
