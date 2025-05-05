// * 2545. Sort the Students by Their Kth Score

function sortTheStudents(score: number[][], k: number): number[][] {
  score.sort((a, b) => b[k] - a[k]);
  return score;
}
