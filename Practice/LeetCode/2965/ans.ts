// * 2695. Array Wrapper

class ArrayWrapper {
  private values: number[]

  constructor(nums: number[]) {
    this.values = nums
  }

  valueOf(): number {
    return this.values.reduce((a, b) => a + b, 0)
  }

  toString(): string {
    return `[${this.values.join(',')}]`
  }
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
