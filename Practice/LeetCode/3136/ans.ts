// * 3136. Valid Word

function isValid(word: string): boolean {
    if (word.length < 3) return false
    let vowels = 0
    let consonants = 0
    for (const char of word) {
        if (/[aeiouAEIOU]/.test(char)) {
            vowels++
            continue
        }
        if (/[a-zA-Z]/.test(char)) {
            consonants++
            continue
        }
        if (/\d/.test(char)) continue
        return false
    }
    return vowels > 0 && consonants > 0
};
