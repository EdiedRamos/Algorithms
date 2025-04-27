// * 3211. Generate Binary Strings Without Adjacent Zeros

function isValidString(s: string): boolean {
  for (let i = 0; i < s.length - 1; i++)
    if (s[i] === "0" && s[i + 1] === "0") return false;
  return true;
}

function validStrings(n: number): string[] {
  const valid: string[] = [];
  const generate = (limitLength: number, currentString: string): void => {
    if (currentString.length === limitLength) {
      if (isValidString(currentString)) {
        valid.push(currentString);
      }
      return;
    }
    if (!isValidString(currentString)) return;
    generate(limitLength, currentString.concat("0"));
    generate(limitLength, currentString.concat("1"));
  };
  generate(n, "");
  return valid;
}
