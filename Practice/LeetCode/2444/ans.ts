// * 2444. Count Subarrays With Fixed Bounds

function countSubarrays(nums: number[], minK: number, maxK: number): number {
  let start = -1;
  let minIdx = -1;
  let maxIdx = -1;
  let ans = 0;
  for (let i = 0; i < nums.length; i++) {
    const curValue = nums[i];
    if (curValue < minK || curValue > maxK) {
      start = i;
    }
    if (curValue === minK) {
      minIdx = i;
    }
    if (curValue === maxK) {
      maxIdx = i;
    }
    ans += Math.max(0, Math.min(minIdx, maxIdx) - start);
  }
  return ans;
}
