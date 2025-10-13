// * 2273. Find Resultant Array After Removing Anagrams

function areAnagram(a: string, b: string): boolean {
  return [...a].sort().join('') === [...b].sort().join('')
}

function removeAnagrams(words: string[]): string[] {
  let change = true
  while (change) {
    change = false
    for (let i = 0; i < words.length - 1; i++) {
      if (areAnagram(words[i], words[i + 1])) {
        words[i + 1] = 'USED'
        change = true
      }
    }
    words = words.filter((v) => v !== 'USED')
  }
  return words
}
