import java.io.*;
import java.util.*;

public class PE_Plus_014 {
    static int[] answers = new int[5000001];
    int winner = 1;
    long winLen = 1;

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        PE_Plus_14 sol = new PE_Plus_14();
        sol.run();
    }

    private void run(){
        if(answers[2] == 0) precompute();
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 0; i < t; i++){
            int n = s.nextInt();
            System.out.println(answers[n]);
        }
    }

    private void precompute(){
        for(int i = 1; i < answers.length; i++){
            long len = len(i);
            if(len >= winLen){
                winner = i;
                winLen = len;
            }
            answers[i] = winner;
        }
    }

    private long len(int n){
        long res = 1;
        while(n > 1){
            if(n % 2 == 0)
                n /= 2;
            else
                n = 3*n+1;
            res++;
        }
        return res;
    }
}
