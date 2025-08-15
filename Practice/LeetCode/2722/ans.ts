// * 2722. Join Two Arrays by ID

type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue }
type ArrayType = { id: number } & Record<string, JSONValue>

function join(arr1: ArrayType[], arr2: ArrayType[]): ArrayType[] {
  const arr2Searching: Record<number, ArrayType> = {}
  const arr1Searching: Record<number, ArrayType> = {}
  const joinedArray: ArrayType[] = []
  for (const value of arr2) arr2Searching[value.id] = value
  for (const value of arr1) arr1Searching[value.id] = value
  // arr1.sort((a, b) => a.id - b.id);
  for (const value of arr1) {
    if (arr2Searching[value.id]) {
      joinedArray.push({ ...value, ...arr2Searching[value.id] })
    } else {
      joinedArray.push(value)
    }
  }
  for (const value of arr2) {
    if (!arr1Searching[value.id]) {
      joinedArray.push(value)
    }
  }
  joinedArray.sort((a, b) => a.id - b.id)
  // console.log({ arr2Searching });
  return joinedArray
}
