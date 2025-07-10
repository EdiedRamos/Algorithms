// * 2044. Count Number of Maximum Bitwise-OR Subsets

function countMaxOrSubsets(nums: number[]): number {
  let maxOr = 0
  let maxLength = 0
  for (let i = 0; i < 1 << nums.length; i++) {
    let or = 0
    for (let j = 0; j < nums.length; j++) {
      if (i & (1 << j)) {
        or |= nums[j]
      }
    }
    if (or > maxOr) {
      maxOr = or
      maxLength = 1
    } else if (or === maxOr) {
      maxLength++
    }
  }
  return maxLength
}
