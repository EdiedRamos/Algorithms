/**
 * @author Yeshayah
 **/

import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

public class P_446 {
    public static void main(String args[]) {
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        String A, B, t, bin1, bin2;
        BigInteger x, y;
        int a, b;
        while (tc --> 0) {
            A = sc.next();
            t = sc.next();
            B = sc.next();
            x = new BigInteger(A, 16);
            y = new BigInteger(B, 16);
            bin1 = x.toString(2);
            bin2 = y.toString(2);
            a = Integer.parseInt(x.toString());
            b = Integer.parseInt(y.toString());
            if (t.equals("+")) {
                a += b;
            } else {
                a -= b;
            }
            for (int i = 0; i < 13 - bin1.length(); i++) {
                pw.print("0");
            }
            pw.print(bin1 + " " + t + " ");
            for (int i = 0; i < 13 - bin2.length(); i++) {
                pw.print("0");
            }
            pw.println(bin2 + " = " + a);
        }
        pw.close();
    }
}
