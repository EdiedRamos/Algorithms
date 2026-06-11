// 39. Combination Sum

function combinationSum(candidates: number[], target: number): number[][] {
  const ans: number[][] = [];
  const path: number[] = [];
  const n = candidates.length;

  const back = (remaining: number, index: number) => {
    if (remaining === 0) {
      ans.push([...path]);
      return;
    }

    for (let i = index; i < n; i++) {
      if (candidates[i] <= remaining) {
        path.push(candidates[i]);
        back(remaining - candidates[i], i);
        path.pop();
      }
    }
  };

  back(target, 0);

  return ans;
}
