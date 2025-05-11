// * 1550. Three Consecutive Odds

function threeConsecutiveOdds(arr: number[]): boolean {
  for (let i = 0; i < arr.length - 2; i++) {
    if ((arr[i] & 1) && (arr[i + 1] & 1) && (arr[i + 2] & 1)) return true;
  }
  return false;
}
