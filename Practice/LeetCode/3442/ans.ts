// * 3442. Maximum Difference Between Even and Odd Frequency I

function maxDifference(s: string): number {
  const frecuency: Record<string, number> = {}
  let maxOdd: number = 0,
    minEven: number = Infinity
  for (const char of s) {
    frecuency[char] = (frecuency[char] ?? 0) + 1
  }
  for (const [, value] of Object.entries(frecuency)) {
    if (value & 1) maxOdd = Math.max(maxOdd, value)
    else minEven = Math.min(minEven, value)
  }
  return maxOdd - minEven
}
