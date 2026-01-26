// 1200. Minimum Absolute Difference

function minimumAbsDifference(arr: number[]): number[][] {
  let ans: number[][] = [];
  let minDiff = Infinity;
  arr.sort((a, b) => a - b);
  for (let i = 0; i < arr.length - 1; i++) {
    const currentDiff = Math.abs(arr[i] - arr[i + 1]);
    if (currentDiff < minDiff) {
      minDiff = currentDiff;
      ans = [[arr[i], arr[i + 1]]];
    } else if (currentDiff === minDiff) {
      ans.push([arr[i], arr[i + 1]]);
    }
  }
  return ans;
}
