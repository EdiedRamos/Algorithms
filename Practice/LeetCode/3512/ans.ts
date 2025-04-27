// * 3512. Minimum Operations to Make Array Sum Divisible by K

function minOperations(nums: number[], k: number): number {
  return nums.reduce((prev, cur) => prev + cur, 0) % k;
}
