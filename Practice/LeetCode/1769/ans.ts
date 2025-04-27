// * 1769. Minimum Number of Operations to Move All Balls to Each Box

function minOperations(boxes: string): number[] {
  const answer: number[] = Array.from({ length: boxes.length }).map(() => 0);
  let leftBalls: number = 0,
    leftBallsMoved: number = 0,
    rightBalls: number = 0,
    rightBallsMoved: number = 0;
  for (let i = 0; i < boxes.length; i++) {
    answer[i] += leftBallsMoved;
    leftBalls += boxes[i] === "1" ? 1 : 0;
    leftBallsMoved += leftBalls;
    const rightIndex = boxes.length - 1 - i;
    answer[rightIndex] += rightBallsMoved;
    rightBalls += boxes[rightIndex] === "1" ? 1 : 0;
    rightBallsMoved += rightBalls;
  }
  return answer;
}
