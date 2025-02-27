// 1337. The K Weakest Rows in a Matrix

interface Information {
  originalIndex: number;
  soldiers: number;
}

function kWeakestRows(mat: number[][], k: number): number[] {
  const information: Information[] = [];
  for (let i = 0; i < mat.length; i++) {
    information.push({
      originalIndex: i,
      soldiers: mat[i].reduce((prev, acum) => prev + acum, 0)
    });
  }
  information.sort((a: Information, b: Information) => {
    return a.soldiers < b.soldiers || (a.soldiers === b.soldiers && a.originalIndex < b.originalIndex) ? -1 : 1;
  });
  // console.log({ information });
  const ans: number[] = [];
  for (let i = 0; i < k; i++) {
    ans.push(information[i].originalIndex);
  }
  return ans;
};
