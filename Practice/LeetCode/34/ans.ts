function lowerBound(nums: number[], target: number): number {
  let l = 0, r = nums.length - 1, c = 0;
  while (l <= r) {
    c = (l + r) >> 1;
    if (nums[c] < target) l = c + 1;
    else r = c - 1;
  }
  return nums[l] === target ? l : -1;
}

function upperBound(nums: number[], target: number): number {
  let l = 0, r = nums.length - 1, c = 0;
  while (r - l > 1) {
    c = (l + r) >> 1;
    if (nums[c] === target) l = c;
    else if (nums[c] < target) l = c + 1;
    else r = c - 1;
  }
  if (nums[r] === target) return r;
  if (nums[c] === target) return c;
  return nums[l] === target ? l : -1;
}

function searchRange(nums: number[], target: number): number[] {
  return [lowerBound(nums, target), upperBound(nums, target)];
};
