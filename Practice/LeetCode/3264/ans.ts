// * 3264. Final Array State After K Multiplication Operations I

function getFinalState(
  nums: number[],
  k: number,
  multiplier: number
): number[] {
  while (k--) {
    let minIndex = 0;
    let minVal = nums[0];
    for (let i = 0; i < nums.length; i++) {
      if (nums[i] < minVal) {
        minVal = nums[i];
        minIndex = i;
      }
    }
    nums[minIndex] *= multiplier;
  }
  return nums;
}
