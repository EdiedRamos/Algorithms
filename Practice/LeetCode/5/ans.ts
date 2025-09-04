// * 5. Longest Palindromic Substring

function isPalindrome(s: string): boolean {
  for (let i = 0; i < s.length >> 1; i++)
    if (s[i] !== s[s.length - i - 1]) return false
  return true
}

function longestPalindrome(s: string): string {
  let longest = ''
  for (let i = 0; i < s.length; i++) {
    for (let j = i; j < s.length; j++) {
      const substr = s.substring(i, j + 1)
      if (
        substr.length > longest.length &&
        isPalindrome(substr) &&
        substr.length > longest.length
      ) {
        longest = substr
      }
    }
  }
  return longest
}
