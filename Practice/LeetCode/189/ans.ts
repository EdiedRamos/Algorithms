// * 189. Rotate Array

/**
  Do not return anything, modify nums in-place instead.
 */
function rotate(nums: number[], k: number): void {
  const extra = [...nums]
  for (let i = 0; i < nums.length; i++) {
    nums[(i + k) % nums.length] = extra[i]
  }
}
