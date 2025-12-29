// 1255. Maximum Score Words Formed by Letters

function maxScoreWords(
  words: string[],
  letters: string[],
  score: number[],
): number {
  const ASCII_A = 97;
  const ALPHABET_LENGTH = 26;
  const available: number[] = Array(ALPHABET_LENGTH).fill(0);
  const combination: number[] = Array(ALPHABET_LENGTH).fill(0);
  const getCharacterIndex = (character: string): number =>
    character.charCodeAt(0) - ASCII_A;
  const n = words.length;
  let maxCombinationScore = 0,
    combinationScore;
  for (const letter of letters) {
    available[getCharacterIndex(letter)]++;
  }
  for (let i = 0; i < 1 << n; i++) {
    for (let c = 0; c < ALPHABET_LENGTH; c++) combination[c] = 0;
    combinationScore = 0;
    for (let j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for (const char of words[j]) combination[getCharacterIndex(char)]++;
      }
    }
    let canCombine = true;
    for (let c = 0; c < ALPHABET_LENGTH; c++) {
      if (combination[c] > available[c]) {
        canCombine = false;
      }
      combinationScore += combination[c] * score[c];
    }
    if (canCombine)
      maxCombinationScore = Math.max(maxCombinationScore, combinationScore);
  }
  return maxCombinationScore;
}
