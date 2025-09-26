// * 611. Valid Triangle Number

function triangleNumber(nums: number[]): number {
  let validTriangles = 0
  nums.sort((a, b) => a - b)
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      let left = j,
        right = nums.length - 1,
        k = j
      while (left <= right) {
        const middle = (left + right) >> 1
        if (nums[middle] < nums[i] + nums[j]) {
          left = middle + 1
          k = middle
        } else {
          right = middle - 1
        }
      }
      validTriangles += k - j
    }
  }
  return validTriangles
}
