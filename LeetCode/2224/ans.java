class Solution {
    public int convertTime(String current, String correct) {
        int count = 0;
        int options[] = {60, 15, 5, 1};
        String part1[] = current.split(":");
        String part2[] = correct.split(":");
        int correctMinutes = Integer.parseInt(part2[0]) * 60 + Integer.parseInt(part2[1]);
        int currentMinutes = Integer.parseInt(part1[0]) * 60 + Integer.parseInt(part1[1]);
        int differ =  correctMinutes - currentMinutes;
        for (int i = 0; i < options.length; i++) {
          while (differ >= options[i]) {
            differ -= options[i];
            count++;
          }
        }
        return count;
    }
}
