// * 3477. Fruits Into Baskets II

function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
  let unplaced = 0;
  let placed = false;
  for (let i = 0; i < fruits.length; i++) {
    placed = false;
    for (let j = 0; j < baskets.length && !placed; j++) {
      if (baskets[j] >= fruits[i]) {
        placed = true;
        baskets[j] = 0;
      }
    }
    if (!placed) unplaced++;
  }
  return unplaced;
};
