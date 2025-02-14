class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findLHS($nums) {
      sort($nums);
      $start = 0; $end = 1; $ans = 0;
      $length = count($nums);
      while ($start < $length) {
        while ($end < $length && ($nums[$start] === $nums[$end] || $nums[$end] - 1 === $nums[$start])) {
          $end++;
        }
        if ($nums[$start] !== $nums[$end - 1]) {
          $ans = max($ans, $end - $start);
        }
        $start++;
      }
      return $ans;
    }
}
