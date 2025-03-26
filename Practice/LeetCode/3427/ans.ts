// * 3427. Sum of Variable Length Subarrays

function subarraySum(nums: number[]): number {
  let ans = 0;
  const prefixSum = [0];
  for (let i = 0; i < nums.length; i++) {
    prefixSum.push(nums[i] + prefixSum[i]);
  }
  for (let i = 0; i < nums.length; i++) {
    const start = Math.max(0, i - nums[i]);
    ans += prefixSum[i + 1] - prefixSum[start];
  }
  return ans;
}
