// 706. Design HashMap

interface MyMap {
  key: number;
  value: number;
}

class MyHashMap {

  private container: MyMap[];

  constructor() {
    this.container = [];
  }

  put(key: number, value: number): void {
    const elementIndex = this.getElementIndex(key);
    if (!~elementIndex) {
      this.container.push({ key, value });
    } else {
      this.container[elementIndex].value = value;
    }
  }

  get(key: number): number {
    const elementIndex = this.getElementIndex(key);
    return !~elementIndex ? -1 : this.container[elementIndex].value;
  }

  remove(key: number): void {
    this.container = this.container.filter(x => x.key !== key);
  }

  private getElementIndex(key: number): number {
    return this.container.findIndex(x => x.key === key);
  }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */
