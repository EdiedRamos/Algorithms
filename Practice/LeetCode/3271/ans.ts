// * 3271. Hash Divided String

function stringHash(s: string, k: number): string {
  let result = "";
  for (let i = 0; i < s.length; i += k) {
    const substring = s.substring(i, i + k);
    let sum = 0;
    for (const char of substring) {
      sum = (sum + char.charCodeAt(0) - 97) % 26;
    }
    result += String.fromCharCode(sum + 97);
  }
  return result;
};