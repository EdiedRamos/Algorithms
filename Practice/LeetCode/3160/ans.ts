function queryResults(limit: number, queries: number[][]): number[] {
  let diffBalls = 0;
  const ans: number[] = [];
  const balls: Record<number, number> = {};
  const colors: Record<number, number> = {};

  const incrementColor = (color: number) => {
    if (!colors[color]) diffBalls++;
    colors[color] = (colors[color] ?? 0) + 1;
  };

  const decrementColor = (color: number) => {
    if (--colors[color] === 0) diffBalls--;
  };

  for (const [ball, color] of queries) {
    const currentColor = balls[ball];

    if (currentColor !== color) {
      if (currentColor !== undefined) decrementColor(currentColor);
      incrementColor(color);
      balls[ball] = color;
    }

    ans.push(diffBalls);
  }

  return ans;
}
