/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_11448 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int _t = Integer.parseInt(br.readLine());
        String p[];
        BigInteger a, b;
        while (_t --> 0) {
            p = br.readLine().split(" ");
            a = new BigInteger(p[0]);
            b = new BigInteger(p[1]);
            a = a.subtract(b);
            pw.println(a);
        }
        pw.close();
    }
}
