class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function areOccurrencesEqual($s) {
        $frecuency = [];
        for ($i = 0; $i < strlen($s); $i++) {
          $char = $s[$i];
          if (!isset($frecuency[$char])) {
            $frecuency[$char] = 0;
          }
          $frecuency[$char]++;
        }
        $unique = array_unique(array_values($frecuency));
        return count($unique) === 1;
    }
}
