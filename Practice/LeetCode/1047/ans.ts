// * 1047. Remove All Adjacent Duplicates In String

function removeDuplicates(s: string): string {
  const remaining: string[] = []
  for (const char of s) {
    if (remaining.length > 0 && remaining[remaining.length - 1] === char) {
      remaining.pop()
    } else {
      remaining.push(char)
    }
  }
  return remaining.join('')
}
