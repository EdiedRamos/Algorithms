// * 1561. Maximum Number of Coins You Can Get

function maxCoins(piles: number[]): number {
  piles.sort((a, b) => b - a);
  let points: number = 0;
  const rounds = piles.length / 3;
  for (let i = 1; i < rounds << 1; i += 2) {
    points += piles[i];
  }
  return points;
}
