class RLEIterator {
  constructor(private encoding: number[]) { }

  private removeCurrent() {
    if (this.encoding[0] === 0) {
      this.encoding.shift();
      this.encoding.shift();
    }
  }

  next(n: number): number {
    while (n > 0 && this.encoding.length > 0) {
      if (n <= this.encoding[0]) {
        const last = this.encoding[1];
        this.encoding[0] -= n;
        this.removeCurrent();
        return last;
      } else {
        n -= this.encoding[0];
        this.encoding[0] = 0;
        this.removeCurrent();
      }
    }
    return -1;
  }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * var obj = new RLEIterator(encoding)
 * var param_1 = obj.next(n)
 */
