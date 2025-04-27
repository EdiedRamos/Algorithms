// * 784. Letter Case Permutation

function applyChange(value: string, index: number): string {
  let parts = [...value];
  if (/[a-z]/.test(parts[index])) {
    parts[index] = parts[index].toUpperCase();
  } else if (/[A-Z]/.test(parts[index])) {
    parts[index] = parts[index].toLowerCase();
  }
  return parts.join("");
}

function letterCasePermutation(s: string): string[] {
  const answer: string[] = [];

  const generate = (index: number, currentString: string): void => {
    if (index === currentString.length) {
      answer.push(currentString);
      return;
    }
    generate(index + 1, currentString);
    if (/[a-zA-Z]/.test(currentString[index])) {
      generate(index + 1, applyChange(currentString, index));
    }
  };
  generate(0, s);
  return answer;
}
