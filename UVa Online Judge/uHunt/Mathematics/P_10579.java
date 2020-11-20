/**
 * @author Yeshayah
 **/

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class P_10579 {
    public static void main(String args[]) {
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc = new Scanner(System.in);
        final int MN = 4800;
        BigInteger a, b, fibo[] = new BigInteger[MN];
        fibo[0] = BigInteger.ZERO;
        fibo[1] = BigInteger.ONE;
        for (int i = 2; i < MN; i++) {
            fibo[i] = fibo[i-1].add(fibo[i-2]);
        }
        while (sc.hasNext()) {
            pw.println(fibo[sc.nextInt()]);
        }
        pw.close();
    }
}
