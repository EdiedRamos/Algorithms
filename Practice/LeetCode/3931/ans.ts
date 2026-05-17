// 3931. Check Adjacent Digit Differences

function isAdjacentDiffAtMostTwo(s: string): boolean {
  const n = s.length;
  for (let i = 0; i < n - 1; i++) {
    if (Math.abs(Number(s[i]) - Number(s[i + 1])) > 2) {
      return false;
    }
  }
  return true;
}
