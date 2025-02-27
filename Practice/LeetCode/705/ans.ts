// 705. Design HashSet

// I didn't want to implement an AVL Tree, so... :)

class MyHashSet {

    private container: number[];

    constructor() {
        this.container = [];
    }

    add(key: number): void {
        if (!this.contains(key)) {
          this.container.push(key);
        }
    }

    remove(key: number): void {
        this.container = this.container.filter(x => x !== key);
    }

    contains(key: number): boolean {
        return this.container.includes(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * var obj = new MyHashSet()
 * obj.add(key)
 * obj.remove(key)
 * var param_3 = obj.contains(key)
 */
