// * 1828. Queries on Number of Points Inside a Circle

type Point = {
  x: number,
  y: number
}

function makePoint(x: number, y: number): Point {
  return {
    x, y
  }
}

function pointsDistance(a: Point, b: Point): number {
  return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
}

function countPoints(points: number[][], queries: number[][]): number[] {
  const ans: number[] = [];
  let count: number = 0;
  for (const [qx, qy, r] of queries) {
    const queryPoint: Point = makePoint(qx, qy);
    count = 0;
    for (const [x, y] of points) {
      const point: Point = makePoint(x, y);
      const distance = pointsDistance(queryPoint, point);
      if (distance <= r) {
        count++;
      }
    }
    ans.push(count);
    count = 0;
  }
  return ans;
};
