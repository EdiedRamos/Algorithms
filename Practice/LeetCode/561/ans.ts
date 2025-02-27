// 561. Array Partition

function arrayPairSum(nums: number[]): number {
  let ans = 0;
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length; i += 2) {
    ans += nums[i];
  }
  return ans;
};
