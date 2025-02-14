function longestMonotonicSubarray(nums: number[]): number {
  const n = nums.length;
  let ans = 0, increasingLength, decreasingLength;
  for (let i = 0; i < n; i++) {
    increasingLength = decreasingLength = 1;
    for (let j = i + 1; j < n && nums[j] > nums[j - 1]; j++) {
      increasingLength++;
    }
    for (let j = i + 1; j < n && nums[j] < nums[j - 1]; j++) {
      decreasingLength++;
    }
    ans = Math.max(ans, Math.max(increasingLength, decreasingLength));
  }
  return ans;
};
