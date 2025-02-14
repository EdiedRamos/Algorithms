/**
 * @param {string} s
 * @return {boolean}
 */
var areOccurrencesEqual = function (s) {
  const frecuency = {};
  for (const char of s)
    frecuency[char] = (frecuency[char] ?? 0) + 1;
  return new Set(Object.values(frecuency)).size === 1;
};
