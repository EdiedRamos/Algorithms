// 1282. Group the People Given the Group Size They Belong To

function groupThePeople(groupSizes: number[]): number[][] {
  const collection: Record<number, number[][]> = {};
  for (let i = 0; i < groupSizes.length; i++) {
    const groupSize = groupSizes[i];
    if (collection[groupSize] === undefined) {
      collection[groupSize] = [[i]];
    } else {
      if (collection[groupSize][0].length === groupSize) {
        collection[groupSize].unshift([i]);
      } else {
        collection[groupSize][0].push(i);
      }
    }
  }
  const answer: number[][] = [];
  for (const value of Object.values(collection)) {
    answer.push(...value);
  }
  return answer;
};
