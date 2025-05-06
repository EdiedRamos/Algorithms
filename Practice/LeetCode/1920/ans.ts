// * 1920. Build Array from Permutation

function buildArray(nums: number[]): number[] {
  const ans: number[] = [];
  for (let i = 0; i < nums.length; i++) {
    ans.push(nums[nums[i]]);
  }
  return ans;
};