function isArraySpecial(nums: number[]): boolean {
  for (let i = 0; i < nums.length - 1; i++) {
    if ((nums[i] & 1) === (nums[i + 1] & 1)) {
      return false;
    }
  }
  return true;
};
