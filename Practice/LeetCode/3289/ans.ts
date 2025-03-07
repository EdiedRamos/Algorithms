// * 3289. The Two Sneaky Numbers of Digitville

function getSneakyNumbers(nums: number[]): number[] {
  const ans: number[] = [];
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] === nums[i + 1]) {
      ans.push(nums[i]);
    }
  }
  return ans;
};