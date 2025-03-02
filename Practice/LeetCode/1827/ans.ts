// 1827. Minimum Operations to Make the Array Increasing

function minOperations(nums: number[]): number {
  let ans = 0;
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] <= nums[i - 1]) {
      ans += nums[i - 1] + 1 - nums[i];
      nums[i] = nums[i - 1] + 1;
    }
  }
  return ans;
};
