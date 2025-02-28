// 1221. Split a String in Balanced Strings

function balancedStringSplit(s: string): number {
  let ans = 0;
  let l = 0, r = 0;
  for (const char of s) {
    if (char === "L") l++;
    else r++;

    if (l === r && l > 0) {
      ans++;
      l = 0;
      r = 0;
    }
  }
  return ans;
};
