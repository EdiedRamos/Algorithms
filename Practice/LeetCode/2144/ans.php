class Solution {

    /**
     * @param Integer[] $cost
     * @return Integer
     */
    function minimumCost($cost) {
        $total = 0;
        rsort($cost);
        for ($i = 1; $i <= count($cost); $i++) {
          if ($i % 3 !== 0) {
            $total += $cost[$i - 1];
          }
        }
        return $total;
    }
}
