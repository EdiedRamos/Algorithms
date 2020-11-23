/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_11115 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String s[];
        while (true) {
            s = br.readLine().split(" ");
            if (s[0].equals("0") && s[1].equals("0")) {
                break;
            }
            pw.println(new BigInteger(s[0]).pow(Integer.valueOf(s[1])));
        }
        pw.close();
    }
}
