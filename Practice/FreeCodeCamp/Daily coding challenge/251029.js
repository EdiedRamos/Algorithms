function toMoneyFormat(value) {
  return `$${value.toFixed(2)}`
}

function calculateTips(mealPrice, customTip) {
  const price = +mealPrice.substring(1)
  const tip = +customTip.substring(0, customTip.length - 1)
  return [
    toMoneyFormat(price * 0.15),
    toMoneyFormat(price * 0.2),
    toMoneyFormat(price * (tip / 100)),
  ]
}
