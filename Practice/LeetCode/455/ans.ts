// * 455. Assign Cookies

function findContentChildren(g: number[], s: number[]): number {
  g.sort((a, b) => a - b)
  s.sort((a, b) => a - b)
  let ch = 0,
    c = 0,
    ans = 0
  while (ch < g.length && c < s.length) {
    if (g[ch] <= s[c]) {
      ans++
      ch++
    }
    c++
  }
  return ans
}
