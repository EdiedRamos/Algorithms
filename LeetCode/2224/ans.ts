
function differTime(a: string, b: string): number {
  const [x1, y1] = a.split(":");
  const [x2, y2] = b.split(":");
  const h1 = +x1, m1 = +y1, h2 = +x2, m2 = +y2;
  const minutesA = h1 * 60 + m1;
  const minutesB = h2 * 60 + m2;
  return minutesB >= minutesA ? minutesB - minutesA : 1499 - minutesA + minutesB; 
}

function convertTime(current: string, correct: string): number {
    const options = [60, 15, 5, 1];
    let times = 0;
    let diff = differTime(current, correct);
    for (const option of options) {
      while (diff >= option) {
        times++;
        diff -= option;
      }
    }
    return times;
};
