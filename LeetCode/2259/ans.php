class Solution {

    /**
     * @param String $number
     * @param String $digit
     * @return String
     */
    function isGreater(string $a, string $b): bool {
    for ($i = 0; $i < strlen($a); $i++) {
        if ($a[$i] === $b[$i]) {
            continue;
        }
        return (int)$a[$i] > (int)$b[$i];
    }
    return false;
}

function removeDigit(string $number, string $digit): string {
    $better = "0";
    $length = strlen($number);

    for ($i = 0; $i < $length; $i++) {
        if ($number[$i] === $digit) {
            $value = "";

            for ($j = 0; $j < $length; $j++) {
                if ($j !== $i) {
                    $value .= $number[$j];
                }
            }

            if ($this->isGreater($value, $better)) {
                $better = $value;
            }
        }
    }

    return $better;
}

}
