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
  while (left < right) {
    if (s[left] !== s[right]) {
      return  isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    } else {
      left++;
      right--;
    }
  }
  return true;
};
