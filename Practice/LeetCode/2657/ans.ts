// * 2657. Find the Prefix Common Array of Two Arrays
// * O(n^2)
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const setB = new Set<number>()
    const n = A.length;
    const ans: number[] = Array.from({ length: n }).map(() => 0)

    for (let i = 0; i < n; i++) {
        setB.add(B[i])

        for (let j = 0; j <= i; j++) {
            if (setB.has(A[j])) {
                ans[i]++
            }
        }
    }

    return ans
};


// * O(n)
// ? As a permutation of n, the maximum frecuency would be 2
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const n = A.length
    const ans: number[] = new Array(n).fill(0)
    const fre: number[] = new Array(n + 1).fill(0)
    for (let i = 0; i < n; i++) {
        fre[A[i]]++
        fre[B[i]]++
        if (fre[A[i]] === 2) ans[i]++
        if (fre[B[i]] === 2 && A[i] !== B[i]) ans[i]++
        if (i > 0) ans[i] += ans[i - 1]
    }
    return ans
};
