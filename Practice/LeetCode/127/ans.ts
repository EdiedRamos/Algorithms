// * 127. Word Ladder

function hasConection(a: string, b: string): boolean {
  let diff = 0
  for (let i = 0; i < a.length; i++) if (a[i] !== b[i]) diff++
  return diff < 2
}

function ladderLength(
  beginWord: string,
  endWord: string,
  wordList: string[]
): number {
  const pendings: string[] = [beginWord]
  const distance: Record<string, number> = { [beginWord]: 1 }
  const used: Record<string, boolean> = {}
  const remaining: Set<string> = new Set(wordList)
  distance[endWord] = Infinity
  while (pendings.length) {
    const current = pendings.shift()
    if (used[current!]) continue
    used[current!] = true
    for (const option of [...remaining]) {
      if (!hasConection(current!, option)) continue
      if (option === endWord) {
        return Math.min(distance[option], distance[current!] + 1)
      }
      if (!used[option]) {
        remaining.delete(option)
        pendings.push(option)
        distance[option] = Math.min(
          distance[option] ?? Infinity,
          distance[current!] + 1
        )
      }
    }
  }
  return distance[endWord] === Infinity ? 0 : distance[endWord]
}
