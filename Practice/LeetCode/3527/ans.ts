// * 3527. Find the Most Common Response

function findCommonResponse(responses: string[][]): string {
  const frecuency: Record<string, number> = {}
  let results: string[] = []
  let max = 0
  for (const response of responses) {
    const diff = new Set(response)
    for (const word of diff) {
      const fre = (frecuency[word] = (frecuency[word] ?? 0) + 1)
      if (fre > max) {
        max = fre
        results = [word]
      } else if (fre === max) {
        results.push(word)
      }
    }
  }
  results.sort((a, b) => (b < a ? 1 : -1))
  return results[0]
}
