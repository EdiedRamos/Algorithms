// * 2396. Strictly Palindromic Number

function isPalidrome(s: string): boolean {
  for (let i = 0; i < s.length >> 1; i++) {
    if (s[i] !== s[s.length - i - 1]) return false;
  }
  return true;
}

function isStrictlyPalindromic(n: number): boolean {
  for (let i = 2; i < n - 1; i++) {
    if (!isPalidrome(n.toString(i))) {
      return false;
    }
  }
  return true;
}
