// * 300. Longest Increasing Subsequence

function lengthOfLIS(nums: number[]): number {
  const n = nums.length;
  const dp = Array(n).fill(0);
  let lis = 0;
  dp[n - 1] = 1;
  for (let i = n - 1; i >= 0; i--) {
    let better = 0;
    for (let j = i + 1; j < n; j++) {
      if (nums[j] > nums[i]) {
        better = Math.max(better, dp[j]);
      }
    }
    dp[i] = better + 1;
    lis = Math.max(lis, dp[i]);
  }
  return lis;
}
