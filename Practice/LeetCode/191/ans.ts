function hammingWeight(n: number): number {
  let count = 0;
  for (let i = 0; i < 32; i++) {
    if (n >> i & 1) count++;
  }
  return count;
};
