// 657. Robot Return to Origin

function judgeCircle(moves: string): boolean {
  let i = 0,
    j = 0;
  for (const char of moves) {
    if (char === "R") i++;
    if (char === "L") i--;
    if (char === "U") j--;
    if (char === "D") j++;
  }
  return i === 0 && j === 0;
}
