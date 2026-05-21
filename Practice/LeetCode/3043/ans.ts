// 3043. Find the Length of the Longest Common Prefix

function longestCommonPrefix(arr1: number[], arr2: number[]): number {
  const prefixes = new Set<number>();
  for (let n of arr1) {
    while (n) {
      prefixes.add(n);
      n = Math.floor(n / 10);
    }
  }
  let maxLength = 0;
  for (let n of arr2) {
    while (n) {
      if (prefixes.has(n)) {
        maxLength = Math.max(maxLength, Math.floor(Math.log10(n)) + 1);
        break; // * cuz if it has a prefix, it can't have a longer prefix
      }
      n = Math.floor(n / 10);
    }
  }
  return maxLength;
}
