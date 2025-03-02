// 2697. Lexicographically Smallest Palindrome

function makeSmallestPalindrome(s: string): string {
  let l = 0, r = s.length - 1;
  const letters = [...s];
  while (l < r) {
    if (letters[l] !== letters[r]) {
      if (letters[l] < letters[r]) {
        letters[r] = letters[l];
      } else {
        letters[l] = letters[r];
      }
    }
    l++;
    r--;
  }
  return letters.join("");
};
