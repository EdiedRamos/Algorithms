// * 901. Online Stock Span

class StockSpanner {

    private stock: number[]

    constructor() {
        this.stock = []
    }

    next(price: number): number {
        let span = 1
        for (let i = this.stock.length - 1; i >= 0 && this.stock[i] <= price; i--) span++;
        this.stock.push(price)
        return span
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */
