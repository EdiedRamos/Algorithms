// 3889. Mirror Frequency Distance

function getDigitMirror(digit: string): string {
  return String(9 - +digit);
}

function getLeetterMirror(letter: string): string {
  return String.fromCharCode(122 - (letter.charCodeAt(0) - 97));
}

function getMirrorValue(value: string): string {
  return value.charCodeAt(0) < 58
    ? getDigitMirror(value)
    : getLeetterMirror(value);
}

function mirrorFrequency(s: string): number {
  let ans = 0;
  const used = new Array(128).fill(0);
  const freq = new Array(128).fill(0);
  for (const char of s) freq[char.charCodeAt(0)]++;
  for (const char of s) {
    const charAscii = char.charCodeAt(0);
    if (!used[charAscii]) {
      const mirror = getMirrorValue(char).charCodeAt(0);
      ans += Math.abs(freq[charAscii] - freq[mirror]);
      used[charAscii] = 1;
      used[mirror] = 1;
    }
  }
  return ans;
}
