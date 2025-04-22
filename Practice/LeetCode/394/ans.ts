// * 394. Decode String

function decodeString(s: string): string {
  if (!s.includes("[")) {
    return s;
  }

  let decoded: string = "";
  let nesting: string = "";
  let k: number = 0;
  let nestingLength: number = 0;
  for (const char of s) {
    if (char === "[") {
      nestingLength++;
      if (nestingLength > 1) {
        nesting += char;
      }
    } else if (char === "]") {
      nestingLength--;
      if (nestingLength === 0) {
        const solvedNesting = decodeString(nesting);
        decoded += solvedNesting.repeat(k);
        k = 0;
        nesting = "";
      } else {
        nesting += char;
      }
    } else if (nestingLength > 0) {
      nesting += char;
    } else if (/[0-9]/.test(char)) {
      k *= 10;
      k += Number(char);
    } else {
      decoded += char;
    }
  }
  return decoded;
}
