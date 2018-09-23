import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PE_Plus_10 {
    static long[] sums;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int[] input = new int[t];
        int max = 0;
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            input[a0] = n;
            if(max < n)
                max = n;
        }

        boolean [] sieve = new boolean[max+1];
        sums = new long[sieve.length];
        sums[1] = 1;
        sums[2] = 2;

        populate(sieve);
        sum(sieve, max);

        for(int n : input){
            while(sums[n] == 0)
                n--;
            System.out.println(sums[n]);
        }
    }

    static void populate(boolean[]sieve){
        int max = (int)Math.sqrt(sieve.length);
        for(int i = 3; i <= max; i+=2){
            for(int j = 3*i; j < sieve.length; j += 2*i)
                sieve[j] = true;
            if(sieve[i]) continue;
        }
    }

    static void sum(boolean[] sieve, int n){
        long total = 2;
        for(int i = 3; i <= n; i += 2)
            if(!sieve[i]){
                total += i;
                sums[i] = total;
            }
    }
}
