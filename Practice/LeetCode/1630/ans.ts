// * 1630. Arithmetic Subarrays

function isArithmetic(left: number, right: number, values: number[]): boolean {
  const subarray: number[] = [];
  for (let i = left; i <= right; i++) {
    subarray.push(values[i]);
  }
  subarray.sort((a, b) => a - b);
  const difference = subarray[0] - subarray[1];
  for (let i = 0; i < subarray.length - 1; i++) {
    if (subarray[i] - subarray[i + 1] !== difference) return false;
  }
  return true;
}

function checkArithmeticSubarrays(
  nums: number[],
  l: number[],
  r: number[]
): boolean[] {
  const ans: boolean[] = [];
  const m = l.length;
  for (let i = 0; i < m; i++) {
    ans.push(isArithmetic(l[i], r[i], nums));
  }
  return ans;
}
