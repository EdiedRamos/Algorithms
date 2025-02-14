// coder: Yeshayah

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_787 {
    // String to int
    static int _int(String s) {
        return Integer.parseInt(s);
    }
    // main
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String input[];
        int n;
        BigInteger data[] = new BigInteger[105];
        BigInteger product, maximum;
        while (true) {
            try {
                input = br.readLine().split(" ");
                n = input.length - 1;
                if (n < 1) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    data[i] = new BigInteger(input[i]);
                }
                maximum = data[0];
                for (int i = 0; i < n; i++) {
                    product = BigInteger.ONE;
                    for (int j = i; j < n; j++) {
                        product = product.multiply(data[j]);
                        if (maximum.compareTo(product) < 0) {
                            maximum = product;
                        }
                    }
                }
                pw.println(maximum);
            } catch(Exception e) {
                break;
            }
        }
        pw.close();
    }
}
