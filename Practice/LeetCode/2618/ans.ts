// 2618. Check if Object Instance of Class

function checkIfInstanceOf(obj: any, classFunction: any): boolean {
  // while (![null, undefined].includes(obj)) {
  //   if (Object.getPrototypeOf(obj) === classFunction?.prototype) return true;
  //   obj = Object.getPrototypeOf(obj);
  // }
  // return false;
  return typeof classFunction !== "function" || [null, undefined].includes(obj)
    ? false
    : Object(obj) instanceof classFunction;
}

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
