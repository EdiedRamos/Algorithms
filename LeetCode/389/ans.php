<? // TODO: Delete this for leetcode
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return String
     */
    function findTheDifference($s, $t) {
      $pa = str_split($s);
      sort($pa);
      $pb = str_split($t);
      sort($pb);
      for ($i = 0; $i < count($pa); $i++) {
        if ($pa[$i] !== $pb[$i]) return $pb[$i];
      }
      return $pb[count($pb) - 1];
    }
}
