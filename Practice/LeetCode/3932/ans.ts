// 3932. Count K-th Roots in a Range

function countKthRoots(l: number, r: number, k: number): number {
  if (k === 1) {
    return r - l + 1;
  }

  const getKthRoot = (n: number): number => {
    if (n < 1) return 0;
    if (n < 2) return 1;
    let root = Math.floor(Math.pow(n, 1 / k) + 1e-9);
    if (Math.pow(root, k) > n) {
      root--;
    }
    return root;
  };

  let ans = getKthRoot(r) - getKthRoot(l - 1);
  if (!l) ans++;
  return ans;
}
