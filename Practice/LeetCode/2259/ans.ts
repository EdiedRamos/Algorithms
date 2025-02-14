function isGreater(a: string, b: string): boolean {
  for (let i = 0; i < a.length; i++) {
    if (a[i] === b[i]) continue;
    return +a[i] > +b[i];
  }
  return false;
}

function removeDigit(number: string, digit: string): string {
  let better = "0";
  for (let i = 0; i < number.length; i++) {
    if (number[i] === digit) {
      let value = "";
      for (let j = 0; j < number.length; j++) {
        if (j !== i) {
          value += number[j];
        }
      }
      if (isGreater(value, better)) {
        better = value;
      }
    }
  }
  return better;
};
