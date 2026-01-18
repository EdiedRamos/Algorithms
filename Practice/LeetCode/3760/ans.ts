// 3760. Maximum Substrings With Distinct Start

function maxDistinct(s: string): number {
  // const diff: Set<string> = new Set();
  // for (const char of s) {
  //   diff.add(char);
  // }
  // return diff.size;

  const ASCII_A = 97,
    ALPHABET_LENGTH = 26;
  const alphabet: number[] = Array(ALPHABET_LENGTH).fill(0);
  let maxDisctinctCount = 0;
  for (const char of s) {
    alphabet[char.charCodeAt(0) - ASCII_A]++;
  }
  for (let i = 0; i < ALPHABET_LENGTH; i++) {
    maxDisctinctCount += alphabet[i] ? 1 : 0;
  }
  return maxDisctinctCount;
}
