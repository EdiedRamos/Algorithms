/**
 * @author Yeshayah
 **/

import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigDecimal;

public class P_10464 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int tc = sc.nextInt();
        while (tc --> 0) {
            BigDecimal a = new BigDecimal(sc.next()).add(new BigDecimal(sc.next()));
            a = a.stripTrailingZeros();
            pw.println(a.toString().contains(".") ? a : a.toString().concat(".0"));
        }
        pw.close();
    }
}
