function threeSumMulti(arr: number[], target: number): number {
  const frecuency: Record<number, number> = {};
  const MOD = 1e9 + 7;
  let ans = 0;
  for (let i = 0; i < arr.length; i++) {
    if (frecuency[target - arr[i]]) {
      ans = (ans + frecuency[target - arr[i]]) % MOD;
    }
    for (let j = 0; j < i; j++) {
      frecuency[arr[i] + arr[j]] = (frecuency[arr[i] + arr[j]] ?? 0) + 1;
    }
  }
  return ans;
};
