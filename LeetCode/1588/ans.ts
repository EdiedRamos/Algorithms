function sumOddLengthSubarrays(arr: number[]): number {
  let ans = 0;
  for (let i = 1; i <= arr.length; i += 2) {
    for (let j = 0; j <= arr.length - i; j++) {
      for (let k = 0; k < i; k++) {
        ans += arr[j + k];
      }
    }
  }
  return ans;
};
