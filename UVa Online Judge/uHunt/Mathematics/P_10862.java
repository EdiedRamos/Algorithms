/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_10862 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String n;
        BigInteger f[] = new BigInteger[4001];
        f[0] = BigInteger.ZERO;
        f[1] = BigInteger.ONE;
        for (int i = 2; i < 4001; i++) {
            f[i] = f[i-1].add(f[i-2]);
        }
        while (true) {
            n = br.readLine();
            if (n.equals("0")) {
                break;
            }
            pw.println(f[Integer.valueOf(n) << 1]);
        }
        pw.close();
    }
}
