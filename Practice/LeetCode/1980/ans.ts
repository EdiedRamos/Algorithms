// 1980. Find Unique Binary String

function swap(str: string) {
  return str === "0" ? "1" : "0";
}

function findDifferentBinaryString(nums: string[]): string {
  const n = nums.length;
  const base = "0".repeat(n).split("");
  let ans = "";

  const dfs = (current: string[], index: number): void => {
    const currentStr = current.join("");
    if (!nums.includes(currentStr)) {
      ans = currentStr;
    }
    if (index >= current.length) return;
    current[index] = swap(current[index]);
    dfs(current, index + 1);
    current[index] = swap(current[index]);
  }
  dfs(base, 0);

  return ans.length ? ans : swap(nums[0]);
};
