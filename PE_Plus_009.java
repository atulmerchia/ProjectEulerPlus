import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PE_Plus_009 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            System.out.println(solve(n));
        }
    }

    static int solve(int n){
        for(int a = 1; a < n/2; a++)
            for(int b = 1; b < a; b++){
                int c = n-a-b;
                if(c*c == a*a + b*b)
                    return a*b*c;
            }
        return -1;
    }
}
