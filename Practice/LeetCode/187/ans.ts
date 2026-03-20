// 187. Repeated DNA Sequences

function findRepeatedDnaSequences(s: string): string[] {
  const answer: string[] = [];
  const counter = new Map<string, number>();
  for (let i = 0; i < s.length - 9; i++) {
    const secuence = s.substring(i, i + 10);
    counter.set(secuence, (counter.get(secuence) ?? 0) + 1);
    if (counter.get(secuence) === 2) answer.push(secuence);
  }
  return answer;
}
