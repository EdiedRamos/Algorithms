// * 2433. Find The Original Array of Prefix Xor

function findArray(pref: number[]): number[] {
  for (let i = pref.length - 1; i > 0; i--) {
    pref[i] ^= pref[i - 1];
  }
  return pref;
}
