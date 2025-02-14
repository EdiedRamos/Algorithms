class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function minimumMoves($s) {
      $ans = 0;
      $i = 0;
      while ($i < strlen($s)) {
        if ($s[$i] === "X") {
          $ans++;
          $i += 3;
        } else {
          $i++;
        }
      }
      return $ans;
    }
}
