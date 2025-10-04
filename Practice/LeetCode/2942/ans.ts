// * 2942. Find Words Containing Character

function findWordsContaining(words: string[], x: string): number[] {
  const ans: number[] = []
  words.forEach((word, index) => {
    if (word.includes(x)) {
      ans.push(index)
    }
  })
  return ans
}
