// 796. Rotate String

function rotateString(s: string, goal: string): boolean {
  if (s.length !== goal.length) return false;
  return s.concat(s).includes(goal);
}
