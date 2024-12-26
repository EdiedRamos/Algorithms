function differTime(a: string, b: string): number {
  const [x1, y1] = a.split(":");
  const [x2, y2] = b.split(":");
  return  (+x2 * 60 + +y2) - (+x1 * 60 + +y1);
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
