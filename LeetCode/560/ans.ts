function subarraySum(nums: number[], k: number): number {
  let prefixSum = 0;
  const frecuency: Record<number, number> = {};
  frecuency[0] = 1;
  let ans = 0;
  for (const x of nums) {
    prefixSum += x;
    if (frecuency[prefixSum - k]) {
      ans += frecuency[prefixSum - k];
    }
    frecuency[prefixSum] = (frecuency[prefixSum] ?? 0) + 1;
  }
  return ans;
};
