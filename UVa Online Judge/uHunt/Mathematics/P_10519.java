/**
 * @author Yeshayah
 **/

import java.util.Scanner;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_10519 {
    public static void main(String args[]) {
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        BigInteger b, c;
        while (sc.hasNext()) {
            b = new BigInteger(sc.next());
            if (b.equals(BigInteger.ZERO)) {
                pw.println(1);
                continue;
            }
            c = b;
            c = c.subtract(BigInteger.ONE);
            b = b.multiply(c);
            b = b.add(BigInteger.valueOf(2));
            pw.println(b);
        }
        pw.close();
    }
}
