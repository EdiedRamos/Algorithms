// * 3. Longest Substring Without Repeating Characters

function lengthOfLongestSubstring(s: string): number {
  const caracterPosition: Record<string, number> = {}
  let start = 0,
    best = 0,
    maxStart = 0
  for (let i = 0; i < s.length; i++) {
    if (
      caracterPosition[s[i]] !== undefined &&
      caracterPosition[s[i]] >= maxStart
    ) {
      start = caracterPosition[s[i]]
      while (start < i && s[start] === s[i]) start++
    }
    best = Math.max(best, i - start + 1)
    caracterPosition[s[i]] = i
    maxStart = Math.max(maxStart, start)
  }
  return best
}
