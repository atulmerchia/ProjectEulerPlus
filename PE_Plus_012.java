import java.io.*;
import java.util.*;

public class PE_Plus_012 {
    public static void main(String[] args) {
        int [] ans = new int[1001];
        int tri = 3;
        int nth = 2;
        ans[1] = 3;
        while(true){
            tri += ++nth;
            int div = getDivisors(tri);
            if(div > 1000){
                ans[1000] = tri;
                break;
            }
            else if(ans[div-1] == 0)
                ans[div-1] = tri;
        }
        for(int i = 999; i > 0; i--)
            if(ans[i] == 0 || ans[i] > ans[i+1])
                ans[i] = ans[i+1];

        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 0; i < t; i++)
            System.out.println(ans[s.nextInt()]);
    }

    private static int getDivisors(int tri){
        int ans = 1;
        while(tri % 2 == 0){
            tri /= 2;
            ans++;
        }
        for(int i = 3; i*i <= tri; i+=2){
            int count = 1;
            while(tri % i == 0){
                count++;
                tri /= i;
            }
            ans *= count;
        }
        if(tri > 1)
            ans*=2;
        return ans;
    }
}
