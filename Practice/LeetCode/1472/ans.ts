// * 1472. Design Browser History

class BrowserHistory {
  private history: string[];
  private currentIndex: number;

  constructor(homepage: string) {
    this.history = [homepage];
    this.currentIndex = 0;
  }

  visit(url: string): void {
    while (this.history.length - 1 > this.currentIndex) {
      this.history.pop();
    }
    this.history.push(url);
    this.currentIndex++;
  }

  back(steps: number): string {
    const minIndex = Math.min(this.currentIndex, steps);
    this.currentIndex -= minIndex;
    return this.history[this.currentIndex];
  }

  forward(steps: number): string {
    const maxIndex = Math.min(
      this.history.length - 1 - this.currentIndex,
      steps
    );
    this.currentIndex += maxIndex;
    return this.history[this.currentIndex];
  }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * var obj = new BrowserHistory(homepage)
 * obj.visit(url)
 * var param_2 = obj.back(steps)
 * var param_3 = obj.forward(steps)
 */
