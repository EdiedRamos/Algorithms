// 1888. Minimum Number of Flips to Make the Binary String Alternating

function minFlips(s: string): number {
  let ans = 1000000;
  const l = s.length;
  s = s + s;
  const n = s.length;
  let optionA = "",
    optionB = "";
  let changesA = 0,
    changesB = 0,
    start = 0;
  for (let i = 0; i < n; i++) {
    optionA += i & 1 ? "0" : "1";
    optionB += !(i & 1) ? "0" : "1";
  }
  for (let i = 0; i < n; i++) {
    if (s[i] !== optionA[i]) changesA++;
    if (s[i] !== optionB[i]) changesB++;

    if (i - start + 1 > l) {
      if (s[start] !== optionA[start]) changesA--;
      if (s[start] !== optionB[start]) changesB--;

      start++;
    }

    if (i - start + 1 === l) ans = Math.min(ans, changesA, changesB);
  }
  return ans;
}
