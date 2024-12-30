/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
  const pa = s.split("").sort();
  const pb = t.split("").sort();
  for (let i = 0; i < s.length; i++) {
    if (pa[i] !== pb[i]) {
      return pb[i];
    }
  }
  return pb[pb.length - 1];
};
