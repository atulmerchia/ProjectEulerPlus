import java.io.*;
import java.util.*;

public class PE_Plus_021 {

    public static void main(String[] args) {
        TreeSet<Integer> amicables = new TreeSet<Integer>();
        for(int a = 2; a < 1e5; a++){
            int b = getDivs(a);
            if(a != b && getDivs(b) == a){
                amicables.add(a);
                if(b <= 1e5)
                    amicables.add(b);
            }
        }
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 0; i < t; i++){
            int sum = 0;
            int n = s.nextInt();
            for(int a : amicables){
                if(a >= n)
                    break;
                else
                    sum += a;
            }
            System.out.println(sum);
        }
    }

    public static int getDivs(int num){
        int num0 = num;
        int ans = 1;
        int count = 0;
        while(num % 2 == 0){
            num /= 2;
            count++;
        }
        if(count > 0)
            ans *= Math.pow(2, count + 1) - 1;
        for(int i = 3; i * i <= num; i+=2){
            count = 0;
            while(num % i == 0){
                count++;
                num /= i;
            }
            if(count > 0)
                ans *= (Math.pow(i, count + 1) - 1) / (i-1);
        }
        if(num > 1)
            ans *= num + 1;
        return ans - num0;
    }
}
