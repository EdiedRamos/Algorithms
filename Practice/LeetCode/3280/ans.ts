// * 3280. Convert Date to Binary

function toBinary(n: string): string {
  let value = Number(n);
  let binary = "";
  while (value) {
    binary += String(value % 2);
    value >>= 1;
  }
  return [...binary].reverse().join("");
}

function convertDateToBinary(date: string): string {
  const parts = date.split("-");
  return parts.map((n) => toBinary(n)).join("-");
};