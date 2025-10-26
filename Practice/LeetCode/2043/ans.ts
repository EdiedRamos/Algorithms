// * 2043. Simple Bank System

class Bank {
  private numberOfUsers: number
  private accounts: number[]

  constructor(balance: number[]) {
    this.numberOfUsers = balance.length
    this.accounts = balance
  }

  private isValidAccount(account: number): boolean {
    return account > 0 && account <= this.numberOfUsers
  }

  private hasEnoughBalance(account: number, money: number): boolean {
    return this.accounts[account - 1] >= money
  }

  transfer(account1: number, account2: number, money: number): boolean {
    if (!this.isValidAccount(account1) || !this.isValidAccount(account2))
      return false
    if (!this.hasEnoughBalance(account1, money)) return false

    this.accounts[account1 - 1] -= money
    this.accounts[account2 - 1] += money
    return true
  }

  deposit(account: number, money: number): boolean {
    if (!this.isValidAccount(account)) return false
    this.accounts[account - 1] += money
    return true
  }

  withdraw(account: number, money: number): boolean {
    if (!this.isValidAccount(account)) return false
    if (!this.hasEnoughBalance(account, money)) return false
    this.accounts[account - 1] -= money
    return true
  }
}

/**
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */
