/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function(s, t) {
    const fa = {};
    const fb = {};
    for (let i = 0; i < s.length; i++) {
      fa[s[i]] = (fa[s[i]] ?? 0) + 1;
      fb[t[i]] = (fb[t[i]] ?? 0) + 1;
    }
    let ans = 0;
    for (const [key, value] of Object.entries(fa)) {
      const other = fb[key] ?? 0;
      if (other < value) {
        ans += value - other;
      }
    }
    return ans;
};
