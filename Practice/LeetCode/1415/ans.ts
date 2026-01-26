// 1415. The k-th Lexicographical String of All Happy Strings of Length n

function isHappyString(s: string) {
  for (let i = 0; i < s.length - 1; i++) if (s[i] === s[i + 1]) return false;
  return true;
}

function getAllHappyString(n: number): string[] {
  const happyString: string[] = [];
  const globalCombination = Array(n).fill("");
  const back = (index: number, combination: string[]) => {
    if (index === n) {
      const comStr = combination.join("");
      if (isHappyString(comStr)) {
        happyString.push(comStr);
      }
      return;
    }

    for (const cur of ["a", "b", "c"]) {
      combination[index] = cur;
      back(index + 1, combination);
    }
  };
  back(0, globalCombination);
  return happyString;
}

function getHappyString(n: number, k: number): string {
  const happyString = getAllHappyString(n);
  return happyString.length >= k ? happyString[k - 1] : "";
}
