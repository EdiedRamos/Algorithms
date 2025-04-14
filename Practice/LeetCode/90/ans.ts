// * 90. Subsets II

function subsetsWithDup(nums: number[]): number[][] {
    const ans: number[][] = [];
    const diff = new Set<string>();
    nums.sort((a, b) => a - b);
    let flag: boolean;
    for (let i = 0; i < 1 << nums.length; i++) {
        let subset: string = "";
        flag = false;
        for (let j = 0; j < nums.length; j++) {
            if (i & 1 << j) {
                subset += `${flag ? "~" : ""}${String(nums[j])}`;
                flag = true;
            }
        }
        diff.add(subset);
    }
    for (const subset of Array.from(diff)) {
        if (subset.length === 0) ans.push([]);
        else ans.push(subset.split("~").map(Number));
    }
    return ans;
};
