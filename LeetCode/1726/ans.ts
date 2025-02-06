function tupleSameProduct(nums: number[]): number {
  const frecuency: Record<number, number> = {};
  const n = nums.length;
  let ans = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const product = nums[i] * nums[j];
      frecuency[product] = (frecuency[product] ?? 0) + 1;
    }
  }
  for (const [key, value] of Object.entries(frecuency)) {
    ans += 8 * Math.floor(value * (value - 1) >> 1);
  }
  return ans;
};
