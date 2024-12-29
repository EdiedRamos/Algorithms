function gcd(a: number, b: number) {
  while (b !== 0) {
    let tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

function hasGroupsSizeX(deck: number[]): boolean {
  if (deck.length === 1) return false;
  const frecuency: Record<number, number> = {};
  for (const value of deck) {
    frecuency[value] = (frecuency[value] ?? 0) + 1;
  }
  const values = Object.values(frecuency);
  let ans = 0;
  for (const value of values) {
    ans = gcd(ans, value);
  }
  return ans > 1;
};
