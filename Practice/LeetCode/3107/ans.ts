// * 3701. Compute Alternating Sum

function alternatingSum(nums: number[]): number {
  let ans = 0
  for (let i = 0; i < nums.length; i++) {
    if (i & 1) ans -= nums[i]
    else ans += nums[i]
  }
  return ans
}
