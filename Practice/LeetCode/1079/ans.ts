// * 1079. Letter Tile Possibilities

function backtracking(currentIndex: number, usedPosition: boolean[], options: string, answer: Set<string>, currentCombination: string): number {
  
  answer.add(currentCombination);
  
  if (currentIndex >= options.length) return -1;

  for (let i = 0; i < options.length; i++) {
    if (!usedPosition[i]) {
      usedPosition[i] = true;
      backtracking(currentIndex + 1, usedPosition, options, answer, currentCombination + options[i]);
      usedPosition[i] = false;
    }
  }
  return answer.size;
}

function numTilePossibilities(tiles: string): number {
  return backtracking(0, Array.from({ length: tiles.length }).map(() => false), tiles, new Set(), "") - 1;
};