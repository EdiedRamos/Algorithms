function canConstruct(s: string, k: number): boolean {
  if (s.length < k) return false;

  const frecuency: Record<string, number> = {};
  for (const char of s) {
    frecuency[char] = (frecuency[char] ?? 0) + 1;
  }
  let oddCounting = 0;
  for (const value of Object.values(frecuency)) {
    if (value % 2 === 1) {
      oddCounting++;
    }
  }
  return oddCounting <= k;
};
