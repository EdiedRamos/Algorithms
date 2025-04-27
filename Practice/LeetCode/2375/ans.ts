// * 2375. Construct Smallest Number From DI String

function validatePattern(value: string, pattern: string): boolean {
  for (let i = 0; i < pattern.length; i++) {
    if (pattern[i] === "I" && Number(value[i]) >= Number(value[i + 1])) {
      return false;
    }
    if (pattern[i] === "D" && Number(value[i]) <= Number(value[i + 1])) {
      return false;
    }
  }
  return true;
}

function smallestNumber(pattern: string): string {
  let answer: string = "";
  const generate = (
    length: number,
    used: boolean[],
    currentString: string
  ): void => {
    if (answer.length > 0) return;

    if (currentString.length === length) {
      if (validatePattern(currentString, pattern)) {
        answer = currentString;
      }
      return;
    }

    for (let i = 1; i < 10; i++) {
      if (!used[i]) {
        used[i] = true;
        generate(length, used, currentString.concat(String(i)));
        used[i] = false;
      }
    }
  };
  const n = pattern.length + 1;
  generate(
    n,
    Array.from({ length: n }).map(() => false),
    ""
  );
  return answer;
}
