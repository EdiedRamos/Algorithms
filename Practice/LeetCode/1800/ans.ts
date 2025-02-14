function maxAscendingSum(nums: number[]): number {
  let ans = 0, cur;
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    cur = nums[i];
    for (let j = i + 1; j < n && nums[j] > nums[j - 1]; j++) {
      cur += nums[j];
    }
    ans = Math.max(ans, cur);
  }
  return ans;
};
