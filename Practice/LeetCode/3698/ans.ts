// * 3698. Split Array With Minimum Difference

function splitArray(nums: number[]): number {
  const prefixSum: number[] = Array(nums.length).fill(0)
  prefixSum[0] = nums[0]

  for (let i = 1; i < nums.length; i++) {
    prefixSum[i] = nums[i] + prefixSum[i - 1]
  }

  const rangeSum = (start: number, end: number): number => {
    // console.log({ start , end })
    if (end >= prefixSum.length || start < 0 || start > end) return 0
    return prefixSum[end] - (prefixSum[start - 1] ?? 0)
  }

  let maxLeftIndex = 0,
    maxRightIndex = nums.length - 1
  let previous = 0
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > (nums[i - 1] ?? 0)) {
      maxLeftIndex = i
    } else {
      break
    }
  }
  for (let i = nums.length - 1; i >= 0; i--) {
    if (nums[i] < (nums[i - 1] ?? 0)) {
      maxRightIndex--
    } else {
      break
    }
  }
  // maxRightIndex = Math.max(0, maxRightIndex)
  // console.log({ maxLeftIndex, maxRightIndex });
  if (maxRightIndex - maxLeftIndex > 1) return -1
  if (maxRightIndex > maxLeftIndex)
    return Math.abs(
      rangeSum(maxRightIndex, nums.length - 1) - rangeSum(0, maxLeftIndex)
    )

  let leftSum = rangeSum(0, maxLeftIndex - 1)
  let rightSum = rangeSum(maxRightIndex + 1, nums.length - 1)

  if (leftSum < rightSum) leftSum += nums[maxLeftIndex]
  else rightSum += nums[maxRightIndex]

  return Math.abs(leftSum - rightSum)
}
