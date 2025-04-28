// * 3467. Transform Array by Parity

function transformArray(nums: number[]): number[] {
  const evenNumbers: number = nums.filter((n) => (n & 1) === 0).length;
  const ans: number[] = Array.from({ length: evenNumbers }).map(() => 0);
  let remaining = nums.length - evenNumbers;
  while (remaining--) ans.push(1);
  return ans;
}
