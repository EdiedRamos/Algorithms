class RandomizedSet {

  private data: boolean[];
  private history: number[];

  constructor() {
    this.data = [];
    this.history = [];
  }

  insert(val: number): boolean {
    if (this.data[val] !== undefined) return false;
    this.data[val] = true;
    this.history.push(val);
    return true;
  }

  remove(val: number): boolean {
    if (this.data[val] === undefined) return false;
    this.data[val] = undefined;
    this.history = this.history.filter((x) => x !== val);
    return true;
  }

  getRandom(): number {
    const random = Math.floor(Math.random() * this.history.length);
    return this.history[random];
  }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
