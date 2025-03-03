// 443. String Compression

function compress(chars: string[]): number {
  let left = 0, right = 0, i = 0;
  while (right < chars.length) {
    while (chars[right] === chars[left]) right++;
    let length = right - left;
    chars[i++] = chars[left];
    if (length > 1) {
      for (const digit of String(length)) {
        chars[i++] = digit;
      }
    }
    left = right;
  }
  return i;
};
