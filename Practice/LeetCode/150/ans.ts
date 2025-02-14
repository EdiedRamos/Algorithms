function romanToInt(s: string): number {
    const relation = {
      "I": 1,
      "V": 5,
      "X": 10,
      "L": 50,
      "C": 100,
      "D": 500,
      "M": 1000 
    };
    let result = 0;
    for (let i = 0; i < s.length; i++) {
      result += relation[s[i]];
      if (i > 0 && relation[s[i]] > relation[s[i - 1]]) {
        result -= relation[s[i - 1]] << 1;
      }
    }
    return result;
};
