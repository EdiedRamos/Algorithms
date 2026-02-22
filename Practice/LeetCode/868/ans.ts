// 868. Binary Gap

function binaryGap(n: number): number {
  let bits = Array(32).fill(false);
  for (let i = 0; i < 32; i++) {
    if (n & (1 << i)) {
      bits[i] = true;
    }
  }
  let ans = 0;
  for (let i = 0; i < 32; i++) {
    if (!bits[i]) continue;
    for (let j = i + 1; j < 32; j++) {
      if (!bits[j]) continue;
      ans = Math.max(ans, j - i);
      break;
    }
  }
  return ans;
}
