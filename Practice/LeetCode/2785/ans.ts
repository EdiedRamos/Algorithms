function sortVowels(s: string): string {
  const asArray = [...s];
  const vowelRegex = /[aeiouAEIOU]/;
  const vowels = asArray.filter((letter) => vowelRegex.test(letter)).sort();
  let i = 0;
  const newArray = asArray.map((letter) => {
    const isVowel = vowelRegex.test(letter);
    // * This is too slow / vowels.shift()
    // return isVowel ? vowels.shift() : letter;
    return isVowel ? vowels[i++] : letter;
  });
  return newArray.join("");
};
