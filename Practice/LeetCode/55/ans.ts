// * 55. Jump Game

function canJump(nums: number[]): boolean {
  let maxJump = 0
  for (let i = 0; i < nums.length; i++) {
    if (i > maxJump) return false
    maxJump = Math.max(maxJump, nums[i] + i)
  }
  return true
}
