import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PE_Plus_1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            long n = in.nextLong();
            if(n <= 0){
                System.out.println(0);
                continue;
            }
            n--;
            long sum = 0;
            long n3 = n/3;
            long n5 = n/5;
            long n15 = n/15;
            sum = 3*n3*(n3+1) + 5*n5*(n5+1) - 15*n15*(n15+1);
            System.out.println(sum/2);
        }
    }
}
