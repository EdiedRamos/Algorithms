// 1784. Check if Binary String Has at Most One Segment of Ones

function checkOnesSegment(s: string): boolean {
  let flag = false;
  for (const c of s) {
    if (c === "0") flag = true;
    if (c === "1" && flag) return false;
  }
  return true;
};
