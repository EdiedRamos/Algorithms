/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;

public class P_11821 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int tc = Integer.parseInt(br.readLine());
        while (tc --> 0) {
            String s;
            BigDecimal n = BigDecimal.ZERO;
            while (true) {
                s = br.readLine();
                if (s.equals("0")) {
                    break;
                }
                n = n.add(new BigDecimal(s));
            }
            n = n.stripTrailingZeros();
            pw.println(n);
        }
        pw.close();
    }
}
