// * 1641. Count Sorted Vowel Strings

function back(index: number, start: number, limit: number): number {
  if (index === limit) return 1
  let ans = 0
  for (let i = start; i < 5; i++) {
    ans += back(index + 1, i, limit)
  }
  return ans
}

function countVowelStrings(n: number): number {
  return back(0, 0, n)
}
