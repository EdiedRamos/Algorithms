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
