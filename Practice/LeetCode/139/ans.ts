// * 139. Word Break

function wordBreak(
  s: string,
  wordDict: string[],
  memo: Record<string, boolean> = {}
): boolean {
  if (s.length === 0) return true
  // console.log("=>", s)
  if (memo[s] !== undefined) {
    // console.log("DP IS WORKING")
    return memo[s]
  }
  for (const option of wordDict) {
    if (s.startsWith(option)) {
      const remaining = s.substring(option.length)
      memo[remaining] = wordBreak(remaining, wordDict, memo)
      if (memo[remaining]) return true
    }
  }
  return false
}
