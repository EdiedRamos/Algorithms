// * 49. Group Anagrams

function groupAnagrams(strs: string[]): string[][] {
  const answer: Record<string, string[]> = {}
  for (const str of strs) {
    const key = [...str].sort().join('')
    const value = answer[key]
    answer[key] = value ? [...value, str] : [str]
  }
  return Object.entries(answer).map(([_, value]) => value)
}
