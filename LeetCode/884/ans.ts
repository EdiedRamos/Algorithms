function uncommonFromSentences(s1: string, s2: string): string[] {
  const fa: Record<string, number> = {};
  const fb: Record<string, number> = {};
  const ans: string[] = [];
  const pa = s1.split(" "), pb = s2.split(" ");
  for (const word of pa) {
    fa[word] = (fa[word] ?? 0) + 1;
  }
  for (const word of pb) {
    fb[word] = (fb[word] ?? 0) + 1;
  }
  for (const word of pa) {
    if (fa[word] === 1 && !pb.includes(word)) {
      ans.push(word);
    }
  }
  for (const word of pb) {
    if (fb[word] === 1 && !pa.includes(word)) {
      ans.push(word);
    }
  }
  return ans;
};
