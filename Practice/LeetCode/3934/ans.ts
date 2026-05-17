// 3934. Smallest Unique Subarray

function smallestUniqueSubarray(nums: number[]): number {
  const n = nums.length;

  const validateLength = (length: number): boolean => {
    if (!length) return false;

    const firstBase = 100003n;
    const firstBaseMod = 1000000007n;
    const secondBase = 100019n;
    const secondBaseMod = 1000000019n;

    const hashFrecuency = new Map<string, number>();

    let firstBlockHash = 0n,
      secondBlockHash = 0n,
      firstFactorPosition = 1n,
      secondFactorPosition = 1n;

    for (let i = 0; i < length; i++) {
      const currentValue = BigInt(nums[i]);
      firstBlockHash =
        (firstBlockHash * firstBase + currentValue) % firstBaseMod;
      secondBlockHash =
        (secondBlockHash * secondBase + currentValue) % secondBaseMod;
      if (i) {
        firstFactorPosition = (firstFactorPosition * firstBase) % firstBaseMod;
        secondFactorPosition =
          (secondFactorPosition * secondBase) % secondBaseMod;
      }
    }

    let uniqueKey = `${firstBlockHash}-${secondBlockHash}`;
    hashFrecuency.set(uniqueKey, 1);

    for (let i = 1; i <= n - length; i++) {
      const outElement = BigInt(nums[i - 1]);
      const inElement = BigInt(nums[i + length - 1]);

      firstBlockHash =
        (firstBlockHash - outElement * firstFactorPosition) % firstBaseMod;
      firstBlockHash = (firstBlockHash * firstBase + inElement) % firstBaseMod;
      if (firstBlockHash < 0n) {
        firstBlockHash += firstBaseMod;
      }

      secondBlockHash =
        (secondBlockHash - outElement * secondFactorPosition) % secondBaseMod;
      secondBlockHash =
        (secondBlockHash * secondBase + inElement) % secondBaseMod;
      if (secondBlockHash < 0n) {
        secondBlockHash += secondBaseMod;
      }

      uniqueKey = `${firstBlockHash}-${secondBlockHash}`;
      hashFrecuency.set(uniqueKey, (hashFrecuency.get(uniqueKey) || 0) + 1);
    }

    for (let freq of hashFrecuency.values()) {
      if (freq === 1) {
        return true;
      }
    }

    return false;
  };

  let left = 1,
    right = n,
    ans = n;
  while (left <= right) {
    const middle = (left + right) >> 1;
    if (validateLength(middle)) {
      ans = middle;
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  return ans;
}
