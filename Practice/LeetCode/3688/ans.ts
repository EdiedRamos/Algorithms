// * 3688. Bitwise OR of Even Numbers in an Array

function evenNumberBitwiseORs(nums: number[]): number {
  let result = 0
  for (const v of nums) {
    if (!(v & 1)) result |= v
  }
  return result
}
