// * 2404. Most Frequent Even Element

function mostFrequentEven(nums: number[]): number {
  const frecuency: Record<number, number> = {}
  let maxFre = 0,
    minAns = -1
  for (const n of nums) {
    if (!(n & 1)) {
      const fre = (frecuency[n] = (frecuency[n] ?? 0) + 1)
      if (fre > maxFre) {
        maxFre = fre
        minAns = n
      } else if (fre === maxFre && n < minAns) {
        minAns = n
      }
    }
  }
  return minAns
}
