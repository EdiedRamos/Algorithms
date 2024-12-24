function minimumMoves(s: string): number {
  let ans = 0;
  for (let i = 0; i < s.length;) {
    if (s[i] === "X") {
      ans++;
      i += 3;
    } else {
      i++;
    }
  }
  return ans;
};
