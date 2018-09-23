import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PE_Plus_2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            long n = in.nextLong();
            long sum = 0;
            long n1 = 0;
            long n2 = 1;
            long temp;
            while(n2 < n){
                if(n2 % 2 == 0)
                    sum += n2;
                temp = n2;
                n2 += n1;
                n1 = temp;
            }
            System.out.println(sum);
        }
    }
}
