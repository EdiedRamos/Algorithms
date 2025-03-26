// * 1480. Running Sum of 1d Array

function runningSum(nums: number[]): number[] {
  const sum = [nums[0]];
  for (let i = 1; i < nums.length; i++) {
    sum.push(nums[i] + sum[i - 1]);
  }
  return sum;
}
