function dailyTemperatures(temperatures: number[]): number[] {
    const answer: Array<number> = Array(temperatures.length).fill(0);
    const stack: Array<number> = [];
    for (let i: number = 0; i < temperatures.length; i++) {
        while (stack.length && temperatures[stack[stack.length - 1]] < temperatures[i]) {
            const top: number = stack.pop();
            answer[top] = i - top;
        }
        stack.push(i);
    }
    return answer;
};
