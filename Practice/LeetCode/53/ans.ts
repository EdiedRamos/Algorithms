// * 53. Maximum Subarray

function maxSubArray(nums: number[]): number {
  let sum = 0,
    ans = 0
  for (const n of nums) {
    sum += n
    if (sum < 0) sum = 0
    ans = Math.max(ans, sum)
  }
  if (!ans) return Math.max(...nums)
  return ans
}
