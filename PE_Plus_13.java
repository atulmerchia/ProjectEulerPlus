import java.io.*;
import java.util.*;

public class PE_Plus_13 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        double sum = 0;
        double divisor = Math.pow(10, 41);
        for(int i = 0; i < t; i++){
            sum += s.nextDouble()/divisor;
        }
        String str = "" + sum;
        System.out.println(str.charAt(0) + str.substring(2, 11));
    }
}
