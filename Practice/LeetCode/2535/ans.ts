// * 2535. Difference Between Element Sum and Digit Sum of an Array

function differenceOfSum(nums: number[]): number {
  let sum: number = 0;
  let digitSum: number = 0;
  for (const value of nums) {
    sum += value;
    digitSum += String(value)
      .split("")
      .reduce((prev, cur) => prev + Number(cur), 0);
  }

  return Math.abs(sum - digitSum);
}
