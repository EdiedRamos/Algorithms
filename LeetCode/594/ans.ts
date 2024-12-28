function findLHS(nums: number[]): number {
  nums.sort((a, b) => a - b);
  let start = 0, end = 1, ans = 0;
  while (start < nums.length) {
    while (end < nums.length && (nums[end] === nums[start] || (nums[end] - 1 === nums[start]))) {
      end++;
    }
    if (nums[end - 1] !== nums[start]) {
      ans = Math.max(ans, end - start);
    }
    start++;
  }
  return ans;
};
