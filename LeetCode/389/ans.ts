function findTheDifference(s: string, t: string): string {
  const pa: string[] = s.split("").sort();
  const pb: string[] = t.split("").sort();
  for (let i = 0; i < pa.length; i++)
    if (pa[i] !== pb[i]) return pb[i];
  return pb[pb.length - 1];
};
