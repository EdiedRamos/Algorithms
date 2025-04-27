// * 22. Generate Parentheses

function validateParenthes(parentheses: string): boolean {
  let open: number = 0;
  for (const char of parentheses) {
    if (char === "(") {
      open++;
    } else if (char === ")" && open === 0) {
      return false;
    } else {
      open--;
    }
  }
  return open === 0;
}

function generateParenthesis(n: number): string[] {
  const solution: string[] = [];
  const generate = (length: number, currentString: string): void => {
    if (currentString.length === length) {
      if (validateParenthes(currentString)) {
        solution.push(currentString);
      }
      return;
    }
    generate(length, currentString.concat("("));
    generate(length, currentString.concat(")"));
  };
  generate(n * 2, "");
  return solution;
}
