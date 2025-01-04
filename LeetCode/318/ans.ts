function validate(a: boolean[], b: boolean[]): boolean {
  for (let i = 0; i < 26; i++) {
    if (a[i] && b[i]) return false;
  }
  return true;
}

function maxProduct(words: string[]): number {
  let ans = 0;
  const diff: boolean[][] = [];
  for (const word of words) {
    const positions = Array.from({ length: 26 }).map(() => false);
    for (const char of word) {
      positions[char.charCodeAt(0) - 97] = true;
    }
    diff.push(positions);
  }
  for (let i = 0; i < words.length; i++) {
    for (let j = i + 1; j < words.length; j++) {
      if (validate(diff[i], diff[j])) {
        ans = Math.max(ans, words[i].length * words[j].length);
      }
    }
  }
  return ans;
};
