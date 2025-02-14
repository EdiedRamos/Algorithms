function areAlmostEqual(s1: string, s2: string): boolean {
  let diff = 0;
  const areSame = s1.split("").sort().join("") === s2.split("").sort().join("");
  for (let i = 0; i < s1.length; i++) {
    if (s1[i] !== s2[i]) diff++;
  }
  return (diff === 2 || diff === 0) && areSame;
};
