// 942. DI String Match

function diStringMatch(s: string): number[] {
  const ans: number[] = [];
  let lowest = 0, higher = s.length;
  for (const criteria of s) {
    if (criteria === "I") {
      ans.push(lowest++);
    } else {
      ans.push(higher--);
    }
  }
  ans.push(higher);
  return ans;
};
