import java.io.*;
import java.util.*;

public class PE_Plus_023 {
    static boolean [] isAbundant = new boolean[100000];

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        PE_Plus_23 sol = new PE_Plus_23();
        if(!isAbundant[12]) precompute();
        sol.run();
    }

    private static void precompute(){
        for(int i = 12; i < 100000; i++){
            int num = i;
            int threshold = num*2;
            int sum = 1;
            int count = 0;
            while(num % 2 == 0){
                num /= 2;
                count++;
            }
            if(count > 0)
                sum *= Math.pow(2, count + 1) - 1;
            for(int j = 3; j*j <= num; j+=2){
                count = 0;
                while(num % j == 0){
                    count++;
                    num /= j;
                }
                if(count > 0){
                    sum *= (Math.pow(j, count + 1) - 1) / (j-1);
                    if(sum > threshold)
                        break;
                }
            }
            if(num > 1)
                sum *= num + 1;
            isAbundant[i] = (sum > threshold);
        }
    }

    private void run(){
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        boolean yes = false;
        int n = 0;
        while(t-- > 0){
            yes = false;
            n = in.nextInt();
            for(int i = 12; i <= n/2; i++)
                if(isAbundant[i] && isAbundant[n-i]){
                    yes = true;
                    break;
                }
            if(yes)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
