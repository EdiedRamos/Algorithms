// 1404. Number of Steps to Reduce a Number in Binary Representation to One

function numSteps(s: string): number {
  const bitsArray = [...s];
  let it = 0,
    carry;
  while (bitsArray.length > 1) {
    const lastIndex = bitsArray.length - 1;
    carry = 0;
    if (bitsArray[lastIndex] === "1") {
      for (let i = lastIndex; i >= 0; i--) {
        if (bitsArray[i] === "0") {
          bitsArray[i] = "1";
          carry = 0;
          break;
        } else {
          bitsArray[i] = "0";
          carry = 1;
        }
      }
    } else {
      bitsArray.pop();
    }
    if (carry) bitsArray.unshift("1");
    it++;
  }
  return it;
}
