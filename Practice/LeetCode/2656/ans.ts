// 2656. Maximum Sum With Exactly K Elements 

function progression(n: number): number {
  return n * (n + 1) >> 1;
}

function maximizeSum(nums: number[], k: number): number {
  const maxNumber = Math.max(...nums);
  return progression(maxNumber + k - 1) - progression(maxNumber - 1);
};
