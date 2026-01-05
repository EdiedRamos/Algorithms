// 209. Minimum Size Subarray Sum

function minSubArrayLen(target: number, nums: number[]): number {
  const MAX_FLAG = 9999999;
  const suffixArray: number[] = Array(nums.length + 5).fill(0);
  suffixArray[1] = nums[0];
  for (let i = 1; i < nums.length; i++) {
    suffixArray[i + 1] += suffixArray[i] + nums[i];
  }
  let start = 1,
    end = 1;
  let minLen = MAX_FLAG;
  while (end <= nums.length) {
    const currentSum = suffixArray[end] - suffixArray[start - 1];
    if (currentSum >= target) {
      minLen = Math.min(minLen, end - start + 1);
      start++;
    } else {
      end++;
    }
  }
  return minLen === MAX_FLAG ? 0 : minLen;
}
