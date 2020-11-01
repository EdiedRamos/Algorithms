/**
 * @author Yeshayah
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class P_11952 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String _v[], _in[] = new String[5];
        BigInteger A, B, C, R;
        boolean found;
        int a, b, c, x, y, z, _i;
        int _tc = Integer.parseInt(br.readLine());
        while (_tc --> 0) {
            found = false;
            x = y = z = 0;
            _i = 0;
            _v = br.readLine().split(" ");
            for (int i = 0; i < _v.length; i++) {
                if (!_v[i].isEmpty()) {
                    _in[_i++] = _v[i];
                }
            }
            for (char _c : _in[0].toCharArray()) {
                if (_c == '1') {
                    x++;
                }
            }
            for (char _c : _in[2].toCharArray()) {
                if (_c == '1') {
                    y++;
                }
            }
            for (char _c : _in[4].toCharArray()) {
                if (_c == '1') {
                    z++;
                }
            }
            if (x == _in[0].length() && y == _in[2].length() && z == _in[4].length() && x + y == z) {
                pw.println(1);
                continue;
            }
            for (int base = 2; base < 37 && !found; base++) {
                try {
                    A = new BigInteger(_in[0], base);
                    B = new BigInteger(_in[2], base);
                    C = A.add(B);
                    R = new BigInteger(_in[4], base);
                    if (C.compareTo(R) == 0) {
                        pw.println(base);
                        found = true;
                    }
                } catch(Exception e) {}
            }
            if (!found) {
                pw.println("0");
            }
        }
        pw.close();
    }
}
