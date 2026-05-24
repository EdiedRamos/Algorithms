// 1340. Jump Game V

function maxJumps(arr: number[], d: number): number {
  const n = arr.length;
  const memo = Array(n + 5).fill(-1);

  const dfs = (currentIndex: number) => {
    if (memo[currentIndex] !== -1) return;

    memo[currentIndex] = 1;

    for (
      let left = currentIndex - 1;
      left >= 0 && currentIndex - left <= d && arr[currentIndex] > arr[left];
      left--
    ) {
      dfs(left);
      memo[currentIndex] = Math.max(memo[currentIndex], memo[left] + 1);
    }

    for (
      let right = currentIndex + 1;
      right < n && right - currentIndex <= d && arr[currentIndex] > arr[right];
      right++
    ) {
      dfs(right);
      memo[currentIndex] = Math.max(memo[currentIndex], memo[right] + 1);
    }
  };

  for (let i = 0; i < n; i++) {
    dfs(i);
  }

  return Math.max(...memo);
}
