// 1323. Maximum 69 Number

function maximum69Number(num: number): number {
  const parts: string[] = [...String(num)];
  for (let i = 0; i < parts.length; i++) {
    if (parts[i] === "6") {
      parts[i] = "9";
      break;
    }
  }
  return Number(parts.join(""));
};
