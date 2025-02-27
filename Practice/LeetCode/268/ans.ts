// 268. Missing Number

function missingNumber(nums: number[]): number {
  const n = nums.length;
  const totalSum = Math.floor(n * (n + 1) / 2);
  const sum = nums.reduce((prev, acum) => prev + acum, 0);
  return totalSum - sum;
};
