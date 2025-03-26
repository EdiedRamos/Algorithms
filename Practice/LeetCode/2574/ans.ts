// * 2574. Left and Right Sum Differences

function leftRightDifference(nums: number[]): number[] {
  const leftSum = [0];
  for (let i = 1; i < nums.length; i++) {
    leftSum.push(nums[i - 1] + leftSum[i - 1]);
  }
  const rightSum = [0];
  nums.reverse();
  for (let i = 1; i < nums.length; i++) {
    rightSum.push(nums[i - 1] + rightSum[i - 1]);
  }
  rightSum.reverse();
  const diff: number[] = [];
  for (let i = 0; i < nums.length; i++) {
    diff.push(Math.abs(leftSum[i] - rightSum[i]));
  }
  return diff;
}
