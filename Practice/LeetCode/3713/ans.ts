// 3713. Longest Balanced Substring I

function longestBalanced(s: string): number {
  let better = 0;
  const frec = Array<number>(26).fill(0);
  let aux, con;
  for (let i = 0; i < s.length; i++) {
    for (let c = 0; c < 26; c++) frec[c] = 0;
    for (let j = i; j < s.length; j++) {
      frec[s[j].charCodeAt(0) - 97]++;
      aux = -1;
      con = 0;
      for (let k = 0; k < 26; k++) {
        if (!frec[k]) continue;
        if (!~aux) {
          aux = frec[k];
        }
        if (frec[k] !== aux) {
          con = 0;
          break;
        }
        con += aux;
      }
      better = Math.max(better, con);
    }
  }
  return better;
}
