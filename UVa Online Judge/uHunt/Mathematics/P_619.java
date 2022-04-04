// coder: Yeshayah

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class P_619 {
    
    static int getOrdinal(char character) {
        return character - 'a' + 1;
    }
    
    static String numberToText(BigInteger number) {
        String text = "";
        int index = 0;
        BigInteger calc = BigInteger.valueOf(26).multiply(BigInteger.valueOf(26).pow(index));
        while (calc.compareTo(number) < 0) {
            index++;
            calc = BigInteger.ZERO;
            for (int i = 0; i <= index; i++) {
                calc = calc.add(BigInteger.valueOf(26).multiply(BigInteger.valueOf(26).pow(i)));
            }
        }
        while (index >= 0) {
            int ordinal = 26;
            calc = BigInteger.valueOf(ordinal).multiply(BigInteger.valueOf(26).pow(index));
            while (calc.compareTo(number) > 0) {
                ordinal--;
                calc = BigInteger.valueOf(ordinal).multiply(BigInteger.valueOf(26).pow(index));
            }
            text += (char)(96 + ordinal);
            number = number.subtract(calc);
            index--;
        }
        return text;
    }
    
    static BigInteger textToNumber(String text) {
        int size = text.length();
        BigInteger answer = BigInteger.ZERO;
        for (int i = 0; i < size; i++) {
            BigInteger ordinal = new BigInteger(getOrdinal(text.charAt(i)) + "");
            BigInteger pow = new BigInteger("26").pow(size - i - 1);
            answer = answer.add(ordinal.multiply(pow));
        }
        return answer;
    }
    
    public static void main(String args[]) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String input;
        while (true) {
            input = bf.readLine();
            if (input.equals("*")) break;
            Pattern pattern = Pattern.compile("[0-9]");
            Matcher matcher = pattern.matcher(input);
            String text;
            BigInteger number;
            if (matcher.find()) {
                number = new BigInteger(input);
                text = numberToText(number);
            } else {
                text = input;
                number = textToNumber(text);
            }
            pw.print(text);
            for (int i = 0; i < 22 - text.length(); i++) pw.print(" ");
            pw.println(String.format("%,d", number));
        }
        pw.close();
    }
}
