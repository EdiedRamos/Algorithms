/**
 * @param {string} s
 * @return {boolean}
 */
var areOccurrencesEqual = function(s) {
    const frecuency = {};
    for (const char of s) {
      if (frecuency[char] === undefined) frecuency[char] = 0;
      frecuency[char]++;
    }
    const values = Object.values(frecuency);
    return Math.min(...values) === Math.max(...values);
};
