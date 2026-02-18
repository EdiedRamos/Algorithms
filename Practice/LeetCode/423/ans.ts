// 423. Reconstruct Original Digits from English

function originalDigits(s: string): string {
  let ans = "";
  const digits = Array<number>(10).fill(0);
  const frecuency = Array<number>(26).fill(0);

  for (const char of s) {
    frecuency[char.charCodeAt(0) - 97]++;
  }

  const specials: [string, string, number][] = [
    ["z", "zero", 0],
    ["w", "two", 2],
    ["x", "six", 6],
    ["g", "eight", 8],
    ["t", "three", 3],
    ["s", "seven", 7],
    ["v", "five", 5],
    ["f", "four", 4],
    ["o", "one", 1],
    ["i", "nine", 9],
  ];
  for (const [letter, word, digit] of specials) {
    digits[digit] = frecuency[letter.charCodeAt(0) - 97];
    for (const char of word) {
      frecuency[char.charCodeAt(0) - 97] -= digits[digit];
    }
  }

  for (let i = 0; i < 10; i++) {
    ans += String(i).repeat(digits[i]);
  }

  return ans;
}
