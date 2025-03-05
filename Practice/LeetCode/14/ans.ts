// * 14. Longest Common Prefix

function longestCommonPrefix(strs: string[]): string {
  const frecuency = {};
  for (const current of strs) {
    for (let i = 0; i <= current.length; i++) {
      const prefix = current.substring(0, i);
      if (!frecuency[prefix]) frecuency[prefix] = 0;
      frecuency[prefix]++;
    }
  }
  return Object.entries(frecuency).reduce((acum, cur) => {
    const [prefix, frecuency] = cur;
    return frecuency === strs.length && prefix.length > acum.length
      ? prefix
      : acum;
  }, "");
}
