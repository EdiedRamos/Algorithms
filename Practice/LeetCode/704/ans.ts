// 704. Binary Search

function search(nums: number[], target: number): number {
  let l = 0, r = nums.length, c;
  while (l <= r) {
    c = (l + r) >> 1;
    if (nums[c] === target) return c;
    if (nums[c] < target) l = c + 1;
    else r = c - 1;
  }
  return -1;
};
