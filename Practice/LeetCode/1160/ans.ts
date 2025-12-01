// * 1160. Find Words That Can Be Formed by Characters

function canBeFormed(origin: string, available: string[]): boolean {
  const originSorted = [...origin].sort()
  let originPointer = 0
  for (const option of available) {
    if (originSorted[originPointer] === option) {
      originPointer++
    }
  }
  return originPointer === origin.length
}

function countCharacters(words: string[], chars: string): number {
  let result = 0
  const charsSorted = [...chars].sort()
  for (const word of words)
    if (canBeFormed(word, charsSorted)) result += word.length
  return result
}