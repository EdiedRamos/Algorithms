// * 1935. Maximum Number of Words You Can Type

function canBeTypedWords(text: string, brokenLetters: string): number {
  return text
    .split(' ')
    .filter((word) => ![...brokenLetters].some((x) => word.includes(x))).length
}
