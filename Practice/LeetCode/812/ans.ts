// * 812. Largest Triangle Area

function largestTriangleArea(points: number[][]): number {
  let maxArea = 0
  for (let i = 0; i < points.length; i++) {
    const [x1, y1] = points[i]
    for (let j = i + 1; j < points.length; j++) {
      const [x2, y2] = points[j]
      for (let k = j + 1; k < points.length; k++) {
        const [x3, y3] = points[k]
        maxArea = Math.max(
          maxArea,
          0.5 * Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
        )
      }
    }
  }
  return maxArea
}
