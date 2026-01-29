// 648. Replace Words

function replaceWords(dictionary: string[], sentence: string): string {
  const prefixes: Record<string, string[]> = {};
  for (const word of dictionary) {
    if (!prefixes[word[0]]) prefixes[word[0]] = [];
    prefixes[word[0]].push(word);
  }

  const sentenceArray = sentence.split(" ");
  for (let wordIndex in sentenceArray) {
    if (!prefixes[sentenceArray[wordIndex][0]]) continue;
    let betterOption = sentenceArray[wordIndex];
    for (const option of prefixes[sentenceArray[wordIndex][0]]) {
      if (
        sentenceArray[wordIndex].startsWith(option) &&
        option.length < betterOption.length
      ) {
        betterOption = option;
      }
    }
    sentenceArray[wordIndex] = betterOption;
  }

  return sentenceArray.join(" ");
}
