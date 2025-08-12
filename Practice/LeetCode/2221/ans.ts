// * 2221. Find Triangular Sum of an Array

function triangularSum(nums: number[]): number {
  let l = nums.length
  while (l > 0) {
    for (let i = 0; i < l - 1; i++) {
      nums[i] = (nums[i] + nums[i + 1]) % 10
    }
    l--
  }
  return nums[0]
}
