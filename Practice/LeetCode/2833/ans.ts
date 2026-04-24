// * 2833. Furthest Point From Origin

function furthestDistanceFromOrigin(moves: string): number {
  let left = 0,
    right = 0;
  for (const move of moves) {
    if (move === "L") left++;
    if (move === "R") right++;
  }
  return Math.abs(left - right) + (moves.length - (left + right));
}
