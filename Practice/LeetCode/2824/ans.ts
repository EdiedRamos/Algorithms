// 2824. Count Pairs Whose Sum is Less than Target
// n is too small to implement binary search

function countPairs(nums: number[], target: number): number {
  let ans = 0;
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] < target) {
        ans++;
      }
    }
  }
  return ans;
};
