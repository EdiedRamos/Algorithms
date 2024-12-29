class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return String[]
     */
    function uncommonFromSentences($s1, $s2) {
      $pa = explode(" ", $s1);
      $pb = explode(" ", $s2);
      $fa = [];
      $fb = [];
      $ans = [];
      for ($i = 0; $i < count($pa); $i++) {
        $fa[$pa[$i]] = ($fa[$pa[$i]] ?: 0) + 1;
      }
      for ($i = 0; $i < count($pb); $i++) {
        $fb[$pb[$i]] = ($fb[$pb[$i]] ?: 0) + 1;
      }
      for ($i = 0; $i < count($pa); $i++) {
        if ($fa[$pa[$i]] === 1 && !isset($fb[$pa[$i]])) {
          $ans[] = $pa[$i];
        }
      }
      for ($i = 0; $i < count($pb); $i++) {
        if ($fb[$pb[$i]] === 1 && !isset($fa[$pb[$i]])) {
          $ans[] = $pb[$i];
        }
      }
      return $ans;
    }
}
