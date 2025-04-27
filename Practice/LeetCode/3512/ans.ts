function minOperations(nums: number[], k: number): number {
  return nums.reduce((prev, cur) => prev + cur, 0) % k;
}
