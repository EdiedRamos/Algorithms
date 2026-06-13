// 3838. Weighted Word Mapping

function mapWordWeights(words: string[], weights: number[]): string {
  let ans = "";
  for (const word of words) {
    let sum = 0;
    for (const char of word) {
      const index = char.charCodeAt(0) - 97;
      sum += weights[index];
    }
    sum %= 26;
    ans += String.fromCharCode(122 - sum);
  }
  return ans;
}
