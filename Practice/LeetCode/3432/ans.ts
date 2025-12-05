// * 3432. Count Partitions with Even Sum Difference

function countPartitions(nums: number[]): number {
  let partitions = 0
  for (let i = 1; i < nums.length; i++) nums[i] += nums[i - 1]
  for (let i = 0; i < nums.length - 1; i++) {
    const leftSum = nums[i]
    const rightSum = nums[nums.length - 1] - nums[i]
    if (Math.abs(leftSum - rightSum) % 2 === 0) partitions++
  }
  return partitions
}
