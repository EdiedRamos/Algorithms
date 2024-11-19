// 12. Integer to Roman

function intToRoman(num: number): string {
    const conversion = {
      1: "I",
      4: "IV",
      5: "V",
      9: "IX",
      10: "X",
      40: "XL",
      50: "L",
      90: "XC",
      100: "C",
      400: "CD",
      500: "D",
      900: "CM",
      1000: "M"
    }
    let roman = "";
    const keys = Object.keys(conversion);
    for (let i = keys.length - 1; i >= 0; i--) {
      while (num >= +keys[i]) {
        roman += conversion[keys[i]];
        num -= +keys[i];
      }
    }
    return roman;
};
