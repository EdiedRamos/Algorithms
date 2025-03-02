// 409. Longest Palindrome

function longestPalindrome(s: string): number {
  const frecuency: Record<number, number> = {};
  let ans = 0;
  let oddFlag = false;
  for (const char of s) {
    frecuency[char] = (frecuency[char] ?? 0) + 1;
  }
  for (const value of Object.values(frecuency)) {
    if (value & 1 && !oddFlag) {
      ans += value;
      oddFlag = true;
      continue;
    }
    if (value % 2 === 1 && value - 1 > 0) ans += value - 1;
    if (!(value & 1)) ans += value;
  }
  return ans;
};
