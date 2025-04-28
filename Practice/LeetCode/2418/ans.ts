// * 2418. Sort the People

function sortPeople(names: string[], heights: number[]): string[] {
  const info: { name: string; height: number }[] = [];
  const n = names.length;
  for (let i = 0; i < n; i++) {
    info.push({ name: names[i], height: heights[i] });
  }
  info.sort((a, b) => b.height - a.height);
  return info.map((data) => data.name);
}
