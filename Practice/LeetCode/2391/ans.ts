// * 2391. Minimum Amount of Time to Collect Garbage

type GarbageType = "G" | "M" | "P";

function filterGarbage(garbage: string, type: GarbageType): number {
  return [...garbage].filter((v) => v === type).length;
}

function evaluateType(
  garbage: string[],
  travel: number[],
  type: GarbageType
): number {
  let typeTime = 0;
  let currentTime = 0;
  for (let i = 0; i < garbage.length; i++) {
    const typeCount = filterGarbage(garbage[i], type);
    currentTime += travel[i];
    if (typeCount > 0) {
      typeTime += currentTime + typeCount;
      currentTime = 0;
    }
  }
  return typeTime;
}

function garbageCollection(garbage: string[], travel: number[]): number {
  travel.unshift(0);
  const glassTime = evaluateType(garbage, travel, "G");
  const paperTime = evaluateType(garbage, travel, "P");
  const metalTime = evaluateType(garbage, travel, "M");
  return glassTime + paperTime + metalTime;
}
