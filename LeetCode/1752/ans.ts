function check(nums: number[]): boolean {
  let iterations = 0, curIndex, n = nums.length;
  let minValueInfo = {
    value: Infinity,
    index: -1
  }
  for (let i = 0; i < n; i++) {
    if (nums[i] <= minValueInfo.value) {
      minValueInfo = {
        value: nums[i],
        index: i
      }
    }
  }
  for (let i = minValueInfo.index; i >= 0 && nums[i] === minValueInfo.value; i--) {
    minValueInfo.index = i;
  }
  // console.log({ minValueInfo });
  curIndex = minValueInfo.index;
  while (iterations < nums.length - 1) {
    if (nums[(curIndex + 1) % n] < nums[curIndex]) {
      // console.log("=>", curIndex);
      return false;
    }
    curIndex = (curIndex + 1) % n;
    iterations++;
  }
  return true;
};
