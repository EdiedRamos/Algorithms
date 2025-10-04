// * 3541. Find Most Frequent Vowel and Consonant

function isVowel(s: string): boolean {
  return [...'aeiou'].some((x) => x === s)
}

function maxFreqSum(s: string): number {
  const vowelFre: Record<string, number> = {}
  const conFre: Record<string, number> = {}
  let maxV = 0,
    maxC = 0
  for (const char of s) {
    if (isVowel(char)) {
      const vf = (vowelFre[char] = (vowelFre[char] ?? 0) + 1)
      maxV = Math.max(maxV, vf)
    } else {
      const cf = (conFre[char] = (conFre[char] ?? 0) + 1)
      maxC = Math.max(maxC, cf)
    }
  }
  return maxV + maxC
}
