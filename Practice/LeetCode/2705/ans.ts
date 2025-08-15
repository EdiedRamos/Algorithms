// * 2705. Compact Object

type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue }
type Obj = Record<string, JSONValue> | Array<JSONValue>

function isObject(obj: unknown) {
  return typeof obj === 'object' && obj !== null && !Array.isArray(obj)
}

function compactObject(obj: Obj | JSONValue): Obj | JSONValue {
  if (!isObject(obj) && !Array.isArray(obj)) {
    return obj
  }
  const array: Array<JSONValue> = []
  const object: Record<string, JSONValue> = {}
  if (Array.isArray(obj)) {
    for (const data of obj) {
      const validated = compactObject(data)
      if (!!validated) array.push(validated)
    }
    return array
  }
  Object.entries(obj).forEach(([key, value]) => {
    const validated = compactObject(value)
    if (!!validated) object[key] = validated
  })
  return object
}
