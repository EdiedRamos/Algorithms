class Solution {
  public char findTheDifference(String s, String t) {
    char pa[] = s.toCharArray();
    char pb[] = t.toCharArray();
    Arrays.sort(pa);
    Arrays.sort(pb);
    for (int i = 0; i < pa.length; i++) {
      if (pa[i] != pb[i])
        return pb[i];
    }
    return pb[pb.length - 1];
  }
}
