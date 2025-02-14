class NumberContainers {

  private container: Record<number, number>;
  private order: Record<number, number[]>;
  private isSorted: Record<number, boolean>;

  constructor() {
    this.container = {};
    this.order = {};
    this.isSorted = {};
  }

  change(index: number, number: number): void {
    const currentValue = this.container[index];
    if (currentValue === number) return;

    const isTheFirstTime = currentValue === undefined;
    if (isTheFirstTime) {
      if (this.order[number] === undefined) this.order[number] = [];
      this.order[number].push(index);
    } else {
      this.order[currentValue] = this.order[currentValue].filter((v) => v !== index);
      this.isSorted[currentValue] = false;
      if (this.order[number] === undefined) this.order[number] = [];
      this.order[number].push(index);
    }
    this.isSorted[number] = false;
    this.container[index] = number;
  }

  find(number: number): number {
    if (this.order[number] === undefined) return -1;
    if (this.order[number].length === 0) return -1;
    if (!this.isSorted[number]) {
      this.order[number].sort((a, b) => a - b);
      this.isSorted[number] = true;
    }
    return this.order[number][0];
  }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
