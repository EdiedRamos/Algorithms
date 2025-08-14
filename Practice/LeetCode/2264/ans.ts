// * 2264. Largest 3-Same-Digit Number in String

function largestGoodInteger(num: string): string {
    let better = "-1";
    for (let i = 0; i < num.length - 2; i++) {
        const current = num.substring(i, i + 3);
        if (current[0] === current[1] && current[1] === current[2] && +current > +better) {
            better = current;
        }
    }
    return better === "-1" ? "" : better;
};
