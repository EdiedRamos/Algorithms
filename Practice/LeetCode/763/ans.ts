// * 763. Partition Labels

function partitionLabels(s: string): number[] {
  const maxIndex: Record<string, number> = {}
  const answer: number[] = []
  for (let i = 0; i < s.length; i++) maxIndex[s[i]] = i
  let currentMax = 0, start = 0
  for (let i = 0; i < s.length; i++) {
    currentMax = Math.max(currentMax, maxIndex[s[i]])
    if (i === currentMax) {
      answer.push(i - start + 1)
      start = i + 1
    }
  }
  return answer
}
