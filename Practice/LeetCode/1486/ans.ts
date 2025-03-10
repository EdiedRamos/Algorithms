// * 1486. XOR Operation in an Array

function xorOperation(n: number, start: number): number {
  let ans = 0;
  for (let i = 0; i < n; i++) {
    ans ^= start + 2 * i;
  }
  return ans;
}
