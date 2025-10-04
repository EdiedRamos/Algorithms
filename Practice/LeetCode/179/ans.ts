// * 179. Largest Number

function largestNumber(nums: number[]): string {
  nums.sort((a, b) => Number(`${b}${a}`) - Number(`${a}${b}`))
  return !nums[0] ? '0' : nums.join('')
}
