import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PE_Plus_3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        long[] inputs = new long[t];
        for(int a0 = 0; a0 < t; a0++){
            long n = in.nextLong();
            inputs[a0] = n;
        }
        long max;
        for(long n : inputs){
            System.out.println(answer(n));
        }
    }

    public static long answer(long n){
        while(n%2 == 0) n/=2;
        if(n == 1) return 1;
        for(long i = 3; i <= (long)Math.sqrt(n); i+=2){
            while(n%i == 0) n/=i;
            if(n == 1) return i;
        }

        return n;
    }
}
