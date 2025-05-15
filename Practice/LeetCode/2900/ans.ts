// * 2900. Longest Unequal Adjacent Groups Subsequence I

function getLongestSubsequence(words: string[], groups: number[]): string[] {
  const answer: string[] = [words[0]];
  for (let i = 1; i < words.length; i++) {
    if (groups[i] !== groups[i - 1]) {
      answer.push(words[i]);
    }
  }
  return answer;
}
