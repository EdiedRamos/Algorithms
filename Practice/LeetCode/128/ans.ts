function longestConsecutive(nums: number[]): number {
  if (!nums.length) return 0;

  let maxLC = 1, curLC = 1;
  const sorted = nums.sort((a, b) => a - b);
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] - nums[i - 1] === 1) {
      curLC++;
      maxLC = Math.max(maxLC, curLC);
    } else if (nums[i] !== nums[i - 1]) {
      curLC = 1;
    }
  }
  return maxLC;
};
