// 680. Valid Palindrome II

function isPalindrome(s: string, l: number, r: number) {
  while (l < r) {
    if (s[l] !== s[r]) return false;
    l++;
    r--;
  }
  return true;
}

function validPalindrome(s: string): boolean {
  let left = 0, right = s.length - 1;
  let deleted = false;
  while (left < right) {
    if (s[left] !== s[right]) {
      if (deleted) return false;
      deleted = true;
      const leftWorks = isPalindrome(s, left + 1, right);
      if (leftWorks) {
        left++;
      } else {
        const rightWorks = isPalindrome(s, left, right - 1);
        if (rightWorks) {
          right--;
        } else {
          return false;
        }
      }
    } else {
      left++;
      right--;
    }
  }
  return true;
};
