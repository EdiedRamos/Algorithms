function convertTemperature(celsius: number): number[] {
    const toKelvin = celsius + 273.15;
    const toFahrenheit = celsius * 1.80 + 32.00;
    return [Number(toKelvin.toFixed(5)), Number(toFahrenheit.toFixed(5))];
};
