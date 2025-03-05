class SmallestInfiniteSet {
  private usedValues: Set<number>;
  private curMin: number;
  private needSort: boolean;

  constructor() {
    this.curMin = 1;
    this.usedValues = new Set();
    this.needSort = false;
  }

  popSmallest(): number {
    if (this.usedValues.size > 0) {
      if (this.needSort) {
        this.usedValues = new Set(
          [...this.usedValues.values()].sort((a, b) => a - b)
        );
        this.needSort = false;
      }
      let value = this.usedValues.values().next().value;
      this.usedValues.delete(value);
      return value;
    }
    return this.curMin++;
  }

  addBack(num: number): void {
    if (num < this.curMin) {
      this.usedValues.add(num);
      this.needSort = true;
    }
  }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
