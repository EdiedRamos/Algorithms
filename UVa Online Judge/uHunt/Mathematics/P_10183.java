/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_10183 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        final int MN = 485;
        BigInteger a, b, fibo[] = new BigInteger[MN];
        String s, prt[];
        int start, r;
        fibo[0] = BigInteger.ONE;
        fibo[1] = BigInteger.valueOf(2);
        for (int i = 2; i < MN; i++) {
            fibo[i] = fibo[i-1].add(fibo[i-2]);
        }
        while (true) {
            s = br.readLine();
            if (s.equals("0 0")) {
                break;
            }
            prt = s.split(" ");
            a = new BigInteger(prt[0]);
            b = new BigInteger(prt[1]);
            start = 0;
            r = 0;
            for (int i = 0; i < MN; i++) {
                if (fibo[i].compareTo(a) > -1) {
                    start = i;
                    break;
                }
            }
            for (int i = start; i < MN; i++) {
                if (fibo[i].compareTo(b) == 1) {
                    break;
                }
                r++;
            }
            pw.println(r);
        }
        pw.close();
    }
}
