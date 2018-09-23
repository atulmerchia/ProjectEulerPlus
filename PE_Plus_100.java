import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import javafx.util.Pair;

public class PE_Plus_100 {
    static final BigInteger MAXDEN = new BigInteger(Long.MAX_VALUE + "");

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            int p = s.nextInt();
            int q = s.nextInt();
            long d = s.nextLong();

            Pair<BigInteger, BigInteger> result = solve(p,q,d);
            if(result == null)
                System.out.println("No solution");
            else
                System.out.println(result.getKey() + " " + result.getValue());
        }
    }

    static Pair<BigInteger, BigInteger> solve(int p, int q, long d) {
        long pq = (long)p*q;
        long root = Math.round(Math.sqrt(pq));
        if(root * root == pq)
            return squareSolve(p,q,d);

        BigInteger biP = new BigInteger(p + "");
        BigInteger biQ = new BigInteger(q + "");
        BigInteger biD = new BigInteger(d + "");

        Pair<BigInteger, BigInteger> result = null;

        for (int div : getFactors(q-p)) {
            BigInteger leftNum = BigInteger.ZERO;
            BigInteger leftDen = new BigInteger(div + "");
            BigInteger rightNum = BigInteger.ONE;
            BigInteger rightDen = BigInteger.ONE;

            Pair<BigInteger, BigInteger> tempRes = null;
            while (leftDen.compareTo(MAXDEN) <= 0 && rightDen.compareTo(MAXDEN) <= 0) {
                BigInteger nextNum = leftNum.add(rightNum);
                BigInteger nextDen = leftDen.add(rightDen);

                boolean less = nextNum.multiply(nextNum).multiply(biQ)
            .compareTo(nextDen.multiply(nextDen).multiply(biP)) < 0;

                if (less) {
                    BigInteger inc = getInc(biP, biQ, leftNum, leftDen, rightNum, rightDen);

                    nextNum = leftNum.add(rightNum.multiply(inc));
                    nextDen = leftDen.add(rightDen.multiply(inc));

                    leftNum = nextNum;
                    leftDen = nextDen;
                }
                else {
                    rightNum = nextNum;
                    rightDen = nextDen;
                }

                BigInteger pairNum = biP.multiply(nextDen);
                BigInteger pairDen = biQ.multiply(nextNum);
                BigInteger reduce = gcd(pairNum, pairDen);

                pairNum = pairNum.divide(reduce);
                pairDen = pairDen.divide(reduce);


                tempRes = less ? getAns(nextNum, nextDen, pairNum, pairDen)
                                : getAns(pairNum, pairDen, nextNum, nextDen);
                if (tempRes != null && tempRes.getValue().compareTo(biD) > 0)
                    break;
            }
            if (tempRes != null && (result == null || tempRes.getValue().compareTo(result.getValue()) < 0))
                result = tempRes;
        }
        return result;
    }

    static BigInteger getInc(BigInteger p, BigInteger q, BigInteger leftNum, BigInteger leftDen, BigInteger rightNum, BigInteger rightDen) {
        int low = 1;
        int high = 10000000;
        int inc = 1;
        while (low <= high) {
            BigInteger mid = new BigInteger((low + high) / 2 + "");

            BigInteger nextNum = leftNum.add(rightNum.multiply(mid));
            BigInteger nextDen = leftDen.add(rightDen.multiply(mid));

            if (nextNum.multiply(nextNum).multiply(q)
            .compareTo(nextDen.multiply(nextDen).multiply(p)) < 0) {
                inc = Math.max(inc, mid.intValue());
                low = mid.intValue() + 1;
            }
            else
                high = mid.intValue() - 1;
        }

        return new BigInteger(inc + "");
    }

    static List<Integer> getFactors(int number) {
        List<Pair<Integer, Integer>> factorization = factorize(number);
        List<Integer> divisors = new ArrayList<Integer>();
        expand(divisors, factorization, 0, 1);
        return divisors;
    }

    static void expand(List<Integer> divisors,
            List<Pair<Integer, Integer>> factorization, int index,
            int divisor) {
        if (index == factorization.size()) {
            divisors.add(divisor);
            return;
        }

        Pair<Integer, Integer> factor = factorization.get(index);
        for (int i = 0; i <= factor.getValue(); i++) {
            expand(divisors, factorization, index + 1, divisor);
            divisor *= factor.getKey();
        }
    }

    static List<Pair<Integer, Integer>> factorize(int n) {
        List<Pair<Integer, Integer>> factorization = new ArrayList<Pair<Integer, Integer>>();
        for (int f = 2; f * f <= n; f++) {
            if (n % f == 0) {
                int count = 0;
                while (n % f == 0) {
                    count++;
                    n /= f;
                }
                factorization.add(new Pair<Integer, Integer>(f, count));
            }
        }
        if (n > 1)
            factorization.add(new Pair<Integer, Integer>(n, 1));
        return factorization;
    }

    static Pair<BigInteger, BigInteger> getAns(BigInteger leftNum, BigInteger leftDen, BigInteger rightNum, BigInteger rightDen) {
        BigInteger mod = leftDen.multiply(rightNum).subtract(leftNum.multiply(rightDen));
        if (leftNum.multiply(rightDen.subtract(rightNum)).mod(mod).signum() != 0
        || leftDen.multiply(rightDen.subtract(rightNum)).mod(mod).signum() != 0
        || rightNum.multiply(leftDen.subtract(leftNum)).mod(mod).signum() != 0
        || rightDen.multiply(leftDen.subtract(leftNum)).mod(mod).signum() != 0)
            return null;
        return new Pair<BigInteger, BigInteger>(rightNum.multiply(leftDen.subtract(leftNum)).divide(mod), rightDen.multiply(leftDen.subtract(leftNum)).divide(mod));
    }

    static BigInteger gcd(BigInteger a, BigInteger b) {
        while(b.signum() != 0){
            BigInteger t = b;
            b = a.mod(b);
            a = t;
        }
        return a;
    }

    static Pair<BigInteger, BigInteger> squareSolve(int p, int q, long d) {
        long w = Math.round(Math.sqrt((long)p*q));
        long prod = (long) q*(q-p);

        Pair<BigInteger, BigInteger> result = null;
        for (long small = 1; small*small < prod; small++) {
            if (prod % small == 0) {
                long large = prod / small;

                long Q2s = large + small;
                if (Q2s % (q * 2) != 0)
                    continue;
                long s = Q2s / (q * 2);

                long W2t = large - small;
                if (W2t % (w * 2) != 0)
                    continue;
                long t = W2t / (w * 2);

                if (s % 2 == 0 || t % 2 == 0)
                    continue;

                long x = (s + 1) / 2;
                long y = (t + 1) / 2;

                if (y > d && (result == null || y < result.getValue().longValue()))
                    result = new Pair<BigInteger, BigInteger>(new BigInteger(x + ""),
                            new BigInteger(y + ""));
            }
        }
        return result;
    }
}
