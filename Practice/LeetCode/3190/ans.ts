// * Using brute force
function minimumOperations(nums: number[]): number {
  let ans = 0;
  for (let v of nums) {
    let up = 0;
    let down = 0;
    let aux = v;
    while (v % 3 !== 0) {
      v++;
      up++;
    }
    v = aux;
    while (v % 3 !== 0) {
      v--;
      down++;
    }
    ans += Math.min(up, down);
  }
  return ans;
};
