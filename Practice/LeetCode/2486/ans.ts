// 2486. Append Characters to String to Make Subsequence

function appendCharacters(s: string, t: string): number {
  let ans = 0;
  for (const char of s) {
    if (char === t[ans]) {
      ans++;
    }
  }
  return t.length - ans;
};
