// 398. Random Pick Index

class Solution {
  indices: Record<number, number[]>;

  constructor(nums: number[]) {
    this.indices = {};
    for (let idx = 0; idx < nums.length; idx++) {
      if (!this.indices[nums[idx]]) this.indices[nums[idx]] = [];
      this.indices[nums[idx]].push(idx);
    }
  }

  pick(target: number): number {
    const n = this.indices[target].length;
    return this.indices[target][Math.floor(Math.random() * n)];
  }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.pick(target)
 */
