function solve(digits: string, index: number, curGroup: string, answer: string[]): void {
  if (index >= digits.length) {
    answer.push(curGroup)
    return;
  }
  const options: string[] = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
  for (const char of options[parseInt(digits[index] ?? "0")]) {
    solve(digits, index + 1, curGroup + char, answer);
  }
}

function letterCombinations(digits: string): string[] {
  if (digits.length === 0) return [];
  const answer = [];
  solve(digits, 0, "", answer);
  return answer;
};
