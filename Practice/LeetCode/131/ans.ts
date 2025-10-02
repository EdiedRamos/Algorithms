// * 131. Palindrome Partitioning

function partition(s: string): string[][] {
  const result: string[][] = []
  const currentPath: string[] = []

  const isPalindrome = (str: string): boolean => {
    for (let i = 0; i < str.length >> 1; i++)
      if (str[i] !== str[str.length - i - 1]) return false
    return true
  }

  const backtrack = (index: number) => {
    if (index === s.length) {
      result.push([...currentPath])
      return
    }
    for (let i = index; i < s.length; i++) {
      const substr = s.substring(index, i + 1)
      if (isPalindrome(substr)) {
        currentPath.push(substr)
        backtrack(i + 1)
        currentPath.pop()
      }
    }
  }

  backtrack(0)

  return result
}
