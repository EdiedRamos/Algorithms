function minSteps(s: string, t: string): number {
  const fa: Record<string, number> = {};
  const fb: Record<string, number> = {};
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

