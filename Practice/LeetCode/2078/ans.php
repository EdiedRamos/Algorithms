class Solution {

    /**
     * @param Integer[] $colors
     * @return Integer
     */
    function maxDistance($colors) {
      $left = 0;
      $right = 0;

      for ($i = count($colors) - 1; $i > 0; $i--) {
        if ($colors[$i] !== $colors[0]) {
          $left = $i;
          break;
        }
      }

      for ($i = 0; $i < count($colors) - 1; $i++) {
        if ($colors[$i] !== $colors[count($colors) - 1]) {
          $right = count($colors) - ($i + 1);
          break;
        }
      }

      return max($left, $right);
    }
}
