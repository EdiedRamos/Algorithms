function multiply(num1: string, num2: string): string {

  // * trivial case
  if ([num1, num2].includes("0")) return "0";

  const products: number[][] = [];
  let carry = 0;
  for (let i = num2.length - 1; i >= 0; i--) {
    const currentProduct: number[] = [];
    for (let j = num1.length - 1; j >= 0; j--) {
      const product = +num2[i] * +num1[j] + carry;
      carry = Math.floor(product / 10);
      const stay = product % 10;
      // console.log(num2[i], "*", num1[j], "=", product);

      currentProduct.unshift(stay);
    }
    if (carry > 0) currentProduct.unshift(carry);
    carry = 0;
    // console.log("product", currentProduct);
    
    products.push(currentProduct);

    if (products.length > 1) {
      for (let k = 0; k < products.length - 1; k++) currentProduct.push(0);

      for (let l = products.length - 1; l > 0; l--) {
        while (products[l - 1].length < products[l].length) {
          products[l - 1].unshift(0);
        }
        while (products[l - 1].length > products[l].length) {
          products[l].unshift(0);
        }
      }
    }
  }

  // console.log(products);

  const resultArray: number[] = [];
  carry = 0;
  for (let y = products[0].length - 1; y >= 0; y--) {
    let sum = 0;
    for (let z = 0; z < products.length; z++) {
      sum += products[z][y];
    }
    sum += carry;
    carry = Math.floor(sum / 10);
    const stay = sum % 10;
    resultArray.unshift(stay);
  }

  while (carry > 0) {
    resultArray.unshift(carry % 10);
    carry = Math.floor(carry / 10);
  }

  return resultArray.join("");
};
