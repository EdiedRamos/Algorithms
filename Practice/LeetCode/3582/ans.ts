// * 3582. Generate Tag for Video Caption

function capitalize(s: string): string {
  return s
    .split('')
    .map((char, index) => char[index === 0 ? 'toUpperCase' : 'toLowerCase']())
    .join('')
}

function generateTag(caption: string): string {
  return '#'
    .concat(
      caption
        .trim()
        .split(' ')
        .map((word, index) =>
          index === 0 ? word.toLowerCase() : capitalize(word)
        )
        .join('')
    )
    .substring(0, 100)
}
