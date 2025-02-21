function calculateRLE(value: string): string {
  let currentLength = 0;
  let rle = "";
  const valueArr = value.split("");
  let curChar = valueArr[0];
  for (const char of valueArr) {
    if (curChar === char) {
      currentLength++;
    } else {
      rle += `${currentLength}${curChar}`;
      curChar = char;
      currentLength = 1;
    }
  }
  return rle.concat(`${currentLength}${curChar}`);
}

function countAndSay(n: number): string {
  let base = "1";
  while (--n) {
    base = calculateRLE(base);
  }
  return base;
};
