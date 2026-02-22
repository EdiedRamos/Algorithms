// 832. Flipping an Image

function flipAndInvertImage(image: number[][]): number[][] {
  for (const row of image) {
    for (let i = 0; i < row.length >> 1; i++) {
      [row[i], row[row.length - i - 1]] = [row[row.length - i - 1], row[i]];
      row[i] ^= 1;
      row[row.length - i - 1] ^= 1;
    }
    if (row.length & 1) row[row.length >> 1] ^= 1;
  }
  return image;
}
