/**
 * @author Yeshayah
 **/

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

public class P_763 {
    
    static BigInteger f[] = new BigInteger[101];
    
    static BigInteger FD(String n) {
        BigInteger r = BigInteger.ZERO;
        for (int i = 0; i < n.length(); i++) {
            if (n.charAt(i) == '1') {
                r = r.add(f[n.length() - i - 1]);
            }
        }
        return r;
    }
    
    static String DF(BigInteger n) {
        if (n.compareTo(BigInteger.ZERO) == 0) {
            return "0";
        }
        String r = "";
        for (int i = 100; i >= 0; i--) {
            if (f[i].compareTo(n) < 1) {
                for (int j = i; j >= 0; j--) {
                    if (f[j].compareTo(n) < 1) {
                        r = r.concat("1");
                        n = n.subtract(f[j]);
                    } else {
                        r = r.concat("0");
                    }
                }
                break;
            }
        }
        return r;
    }
    
    public static void main(String args[]) {
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        boolean j = false;
        f[0] = BigInteger.ONE;
        f[1] = BigInteger.valueOf(2);
        for (int i = 2; i < 101; i++) {
            f[i] = f[i-1].add(f[i-2]);
        }
        while (sc.hasNext()) {
            if (j) {
                pw.println();
            }
            pw.println(DF(FD(sc.next()).add(FD(sc.next()))));
            j = true;
        }
        pw.close();
    }
}
