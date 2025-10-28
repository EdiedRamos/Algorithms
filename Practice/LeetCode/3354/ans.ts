// * 3354. Make Array Elements Equal to Zero

function isValid(start: number, direction: number, nums: number[]): boolean {
  const clone = [...nums]
  while (start >= 0 && start < clone.length) {
    if (clone[start]) {
      clone[start]--
      direction *= -1
    }
    start += direction
  }
  return !!!clone.filter((x) => x).length
}

function countValidSelections(nums: number[]): number {
  let answer = 0
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) continue
    answer += isValid(i, 1, nums) ? 1 : 0
    answer += isValid(i, -1, nums) ? 1 : 0
  }
  return answer
}
