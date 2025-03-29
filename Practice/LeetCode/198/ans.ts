// * 198. House Robber

function rob(nums: number[]): number {
  if (nums.length < 2) return nums[0];
  const dp: number[] = [0, nums[0]];
  for (let i = 1; i < nums.length; i++) {
    dp.push(Math.max(dp[i], nums[i] + dp[i - 1]));
  }
  return dp[dp.length - 1];
}
