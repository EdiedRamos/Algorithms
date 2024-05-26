class TrieNode {
    children: { [key: string]: TrieNode };
    word: string | null;
    constructor() {
        this.children = {};
        this.word = null;
    }
}

class Trie {
    root: TrieNode;
    constructor() {
        this.root = new TrieNode();
    }

    insert(word: string): void {
        let current = this.root;
        for (const char of word) {
            if (!current.children[char]) {
                current.children[char] = new TrieNode();
            }
            current = current.children[char];
        }
        current.word = word;
    }

    getNodebyCharacter(character: string): TrieNode | null {
        return this.root.children[character];
    }
}

let maxX: number;
let maxY: number;
let visited: boolean[][];
let gBoard: string[][];
let trie: Trie;
let allMatches: string[] = [];

function isValidPosition(x: number, y: number): boolean {
    try {

    return x >= 0 && y >= 0 && x < maxY && y < maxX && !visited[x][y];
    } catch {
        console.log({ x, y });
        return false;
    }
}

function backtracking(x: number, y: number, trie: TrieNode) {
    if (!isValidPosition(x, y)) {
        return;
    };

    const curNode = trie.children[gBoard[x][y]];

    if (curNode === undefined) return;

    if (curNode.word !== null) {
        allMatches.push(curNode.word);
        curNode.word = null;
    }

    visited[x][y] = true;
    // searching here
    
    backtracking(x + 1, y, curNode);
    backtracking(x - 1, y, curNode);
    backtracking(x, y + 1, curNode);
    backtracking(x, y - 1, curNode);
    visited[x][y] = false;
}

function findWords(board: string[][], words: string[]): string[] {
    allMatches = [];
    trie = new Trie();
    for (const word of words) {
        trie.insert(word);
    }
    gBoard = board;
    
    maxX = board[0].length;
    maxY = board.length;
    visited = [];
    for (let i = 0; i < maxY; i++) visited.push(Array(maxX).fill(false));
    for (let i = 0; i < maxY; i++) {
        for (let j = 0; j < maxX; j++) {
            backtracking(i, j, trie.root);
        }
    }
    return allMatches;
};
