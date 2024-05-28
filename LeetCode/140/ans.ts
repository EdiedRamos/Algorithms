let AllWords: Set<string> = new Set();

function backtracking(word: string, index: number): void {
    AllWords.add(word);
    if (index === word.length - 1) return;
    backtracking(word.slice(0, index + 1).concat(" ").concat(word.slice(index+1)), index + 2);
    backtracking(word, index + 1);
}

function wordBreak(s: string, wordDict: string[]): string[] {
    AllWords.clear();
    const answer: string[] = [];
    backtracking(s, 0);
    AllWords.forEach((value) => {
        if (value.split(" ").every((sub) => wordDict.includes(sub))) {
            answer.push(value);
        }
    });
    return answer;
};
