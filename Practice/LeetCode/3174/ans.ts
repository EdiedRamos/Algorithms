// 3174. Clear Digits

function clearDigits(s: string): string {
  const sArray = s.split("");
  let digitsLength = sArray.reduce((acum, cur) => /[0-9]/.test(cur) ? acum + 1 : acum, 0);
  for (let i = sArray.length - 1; i >= 0; i--) {
    if (/[a-z]/.test(sArray[i]) && digitsLength) {
      for (let j = i + 1; j < sArray.length; j++) {
        if (/[0-9]/.test(sArray[j])) {
          sArray[i] = "";
          sArray[j] = "";
          digitsLength--;
          break;
        }
      }
    }
  }
  return sArray.filter(x => x !== "").join("");
};
