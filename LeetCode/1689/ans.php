class Solution {

    /**
     * @param String $n
     * @return Integer
     */
    function minPartitions($n) {
        for ($i = 9; $i >= 0; $i--) {
          if (strpos($n, $i) !== false) {
            return $i;
          }
        }
        return 0;
    }
}
