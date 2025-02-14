class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Integer
     */
    function minSteps($s, $t) {
        $frecuencyA = [];
        $frecuencyB = [];
        for ($i = 0; $i < strlen($s); $i++) {
          $charA = $s[$i];
          $charB = $t[$i];
          $frecuencyA[$charA] = ($frecuencyA[$charA] ?? 0) + 1;
          $frecuencyB[$charB] = ($frecuencyB[$charB] ?? 0) + 1;
        }
        $ans = 0;
        foreach ($frecuencyA as $key => $value) {
          $other = $frecuencyB[$key] ?? 0;
          if ($other < $value) {
            $ans += $value - $other;
          }
        }
        return $ans;
    }
}
