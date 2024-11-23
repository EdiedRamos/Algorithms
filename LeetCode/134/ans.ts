function canCompleteCircuit(gas: number[], cost: number[]): number {
    let totalConsume = 0;
    let currentTank = 0;
    let possibleIndex = 0;

    for (let i = 0; i < gas.length; i++) {
      totalConsume += gas[i] - cost[i];
      currentTank += gas[i] - cost[i];
      if (currentTank < 0) {
        currentTank = 0;
        possibleIndex = i + 1;
      }
    }

    return totalConsume < 0 ? -1 : possibleIndex;
};
