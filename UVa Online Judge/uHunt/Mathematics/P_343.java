/**
 * @author Yeshayah
 **/

import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

public class P_343 {
    public static void main(String args[]) {
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        String a, b;
        boolean found;
        BigInteger A, B;
        while (sc.hasNext()) {
            found = false;
            a = sc.next();
            b = sc.next();
            for (int i = 2; i < 37 && !found; i++) {
                try {
                    A = new BigInteger(a, i);
                } catch(Exception e) {continue;}
                for (int j = 2; j < 37 && !found; j++) {
                    try {
                        B = new BigInteger(b, j);
                    } catch(Exception e){continue;}
                    if (A.compareTo(B) == 0) {
                        pw.println(a + " (base " + i + ") = " + b + " (base " + j + ")");
                        found = true;
                    }
                }
            }
            if (!found) {
                pw.println(a + " is not equal to " + b + " in any base 2..36");
            }
        }
        pw.close();
    }
}
