function minimumDistance(a: string, b: string): number {
  const aAscii = a.charCodeAt(0);
  const bAscii = b.charCodeAt(0);
  const greatest = Math.max(aAscii, bAscii);
  const lowest = Math.min(aAscii, bAscii);
  return Math.min(greatest - lowest + 1, 123 - greatest + lowest - 96);
}

function minTimeToType(word: string): number {
  let ans = 0;
  let curLetter = 'a';
  for (const letter of word) {
    ans += minimumDistance(curLetter, letter);
    curLetter = letter;
  }
  return ans;
};
