import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class PE_Plus_111 {
    String createString(int [] filler, String dstring, int d, int len){
        String s = "";
        int i = 0;

        while(i < len && filler[i] < d)
            s += filler[i++];

        s += dstring;

        while(i < len)
            s += filler[i++];

        for(i = 0; i < s.length(); i++)
            if(s.charAt(i) != '0')
                return s.charAt(i) + s.substring(0, i) + s.substring(i+1);
        return s;
    }

    String primeString;
    boolean next(){
        char [] a = primeString.toCharArray();
        for(int i = a.length - 2, j; i >= 0; i--)
            if(a[i+1] > a[i]){
                for(j = a.length - 1; a[j] <= a[i]; j--);
                char temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                int l = i + 1, r = a.length - 1;
                while(l < r){
                    temp = a[l];
                    a[l] = a[r];
                    a[r] = temp;
                    l++;
                    r--;
                }

                primeString = new String(a);
                return true;
            }
        return false;
    }

    boolean increment(int [] filler, int len){
        if(len == 1){
            filler[0]++;
            return filler[0] < 10;
        }
        int index = len-1;
        while(true){
            filler[index]++;
            if(filler[index] > 9)
                if(index == 0)
                    return false;
                else
                    filler[index] = 0;
            else
                break;
            index--;
        }
        boolean oddFound = (filler[0] % 2 == 1);
        for(int i = 1; i < len; i++){
            if(filler[i] < filler[i-1])
                filler[i] = filler[i-1];
            if(filler[i] % 2 == 1)
                oddFound = true;
        }
        return oddFound ? true : increment(filler, len);
    }

    void run(int n, int d){
        if(d == 5){
            solveFives(n);
            return;
        }

        ArrayList<String> answers = new ArrayList<String>();

        for(int fillerLen = 0; fillerLen <= 3; fillerLen++){
            String dstring = "";
            for(int i = fillerLen; i < n; i++)
                dstring += d;

            if(fillerLen == 0)
                if(new BigInteger(dstring).isProbablePrime(10)){
                    System.out.println(dstring);
                    return;
                }
                else
                    continue;

            int [] filler = new int[fillerLen];
            do{
                primeString = createString(filler, dstring, d, fillerLen);
                do{
                    BigInteger b = new BigInteger(primeString);
                    if(b.isProbablePrime(10))
                        answers.add(primeString);
                }while(next());
            }while(increment(filler, fillerLen));
            if(answers.size() > 0){
                Collections.sort(answers);
                for(String s : answers)
                    System.out.print(s + " ");
                System.out.println();
                return;
            }
        }
    }

    void solveFives(int n){
        ArrayList<String> answers = new ArrayList<String>();
        char [] s = new char[n];
        for(int i = 0; i < n; i++)
          s[i] = '5';

        for(char c = '1'; c <= '9'; c+=2){
            s[n-1] = c;
            String str = new String(s);
            if(new BigInteger(str).isProbablePrime(10))
                answers.add(str);
        }
        if(answers.size() > 0){
            for(String x : answers)
                System.out.print(x + " ");
            System.out.println();
            return;
        }

        for(char c = '1'; c <= '9'; c+=2)
            for(char d = '0'; d <= '9'; d++){
                s[n-1] = c;
                for(int i = 0; i < n-1; i++){
                    s[i] = d;
                    String str = new String(s);
                    if(s[0] > '0' && new BigInteger(str).isProbablePrime(10))
                        answers.add(str);
                    s[i] = '5';
                }
            }
        Collections.sort(answers);
        System.out.print(answers.get(0));
        for(int i = 1; i < answers.size(); i++)
            if(!answers.get(i).equals(answers.get(i-1)))
                System.out.print(" " + answers.get(i));
        System.out.println();
    }

    void doStuff(){
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i = 0; i < t; i++)
            run(s.nextInt(), s.nextInt());
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.doStuff();
    }
}
