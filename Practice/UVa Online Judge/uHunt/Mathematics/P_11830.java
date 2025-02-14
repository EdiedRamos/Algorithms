/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_11830 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String p[], _s, a, b;
        BigInteger A;
        while (true) {
            _s = br.readLine();
            if (_s.equals("0 0")) {
                break;
            }
            p = _s.split(" ");
            a = p[0];
            b = p[1];
            b = b.replace(a, "");
            if (b.isEmpty()) {
                b = "0";
            }
            A = new BigInteger(b);
            pw.println(A);
        }
        pw.close();
    }
}
