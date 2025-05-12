// * 2094. Finding 3-Digit Even Numbers

function findEvenNumbers(digits: number[]): number[] {
  const difference: Set<number> = new Set();
  for (let i = 0; i < digits.length; i++) {
    for (let j = 0; j < digits.length; j++) {
      for (let k = 0; k < digits.length; k++) {
        if (i !== j && j !== k && i !== k && digits[i] !== 0 && !(digits[k] & 1)) {
          difference.add((digits[i] * 10 + digits[j]) * 10 + digits[k]);
        }
      }
    }
  }
  return [...difference].sort((a, b) => a - b);
}
