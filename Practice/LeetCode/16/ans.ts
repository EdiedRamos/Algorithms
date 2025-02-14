// Brute force: O(n^3)

function threeSumClosest(nums: number[], target: number): number {
  const n = nums.length;
  let minDiff = Infinity;
  let minSum = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        const curSum = nums[i] + nums[j] + nums[k];
        const curDiff = Math.abs(target - curSum);
        if (curDiff < minDiff) {
          minDiff = curDiff;
          minSum = curSum;
        }
      }
    }
  }
  return minSum;
};
