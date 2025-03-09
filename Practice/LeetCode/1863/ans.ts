// * 1863. Sum of All Subset XOR Totals

function subsetXORSum(nums: number[]): number {
  let ans = 0;
  for (let i = 0; i < 1 << nums.length; i++) {
    let xor = 0;
    for (let j = 0; j < nums.length; j++) {
      if (i & (1 << j)) {
        xor ^= nums[j];
      }
    }
    ans += xor;
  }
  return ans;
}
