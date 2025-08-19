// * 2348. Number of Zero-Filled Subarrays

function combinations(n: number): number {
  return (n * (n + 1)) / 2
}

function zeroFilledSubarray(nums: number[]): number {
  let start = -1,
    end = -1
  let count = 0
  nums.push(-1)
  for (let i = 0; i < nums.length; i++) {
    if (!nums[i]) {
      if (!~start) start = end = i
      else end = i
    } else if (~start) {
      count += combinations(end - start + 1)
      start = -1
    }
  }
  return count
}
