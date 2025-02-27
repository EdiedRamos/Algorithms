// 1365. How Many Numbers Are Smaller Than the Current Number

function smallerNumbersThanCurrent(nums: number[]): number[] {
  let ans: number[] = Array.from({ length: nums.length }).map(() => 0);
  for (let i = 0; i < nums.length; i++) {
    for (let j = 0; j < nums.length; j++) {
      if (i !== j && nums[j] < nums[i]) {
        ans[i]++;
      }
    }
  }
  return ans;
};
