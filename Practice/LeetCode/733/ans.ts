// 733. Flood Fill

function dfs(image: number[][], sr: number, sc: number, color: number, initialColor: number, visited: boolean[][]): void {
  if (image[sr] === undefined || image[sr][sc] === undefined || visited[sr][sc] || image[sr][sc] !== initialColor) return;
  image[sr][sc] = color;
  visited[sr][sc] = true;
  dfs(image, sr + 1, sc, color, initialColor, visited);
  dfs(image, sr - 1, sc, color, initialColor, visited);
  dfs(image, sr, sc + 1, color, initialColor, visited);
  dfs(image, sr, sc - 1, color, initialColor, visited);
}

function floodFill(image: number[][], sr: number, sc: number, color: number): number[][] {
  const m = image.length;
  const n = image[0].length;
  const visited = Array.from({ length: m }).map(() => Array.from({ length: n }).map(() => false));
  // console.log({ visited });
  dfs(image, sr, sc, color, image[sr][sc], visited);
  return image;
};
