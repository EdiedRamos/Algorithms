/**
 * @author Yeshayah
 **/

import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

public class P_10083 {
    public static void main(String args[]) {
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int t, a, b;
            t = sc.nextInt();
            a = sc.nextInt();
            b = sc.nextInt();
            pw.print("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) ");
            if (a < b || (a - b) * Math.log10(t) > 99 || t == 1 || a % b != 0) {
                pw.println("is not an integer with less than 100 digits.");
            } else if (a == b) {
                pw.println("1");
            } else {
                pw.println(new BigInteger(String.valueOf(t)).pow(a).subtract(BigInteger.ONE).divide(new BigInteger(String.valueOf(t)).pow(b).subtract(BigInteger.ONE)));
            }
        }
        pw.close();
    }
}
