import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PE_Plus_11 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[][] grid = new int[20][20];
        for(int grid_i=0; grid_i < 20; grid_i++){
            for(int grid_j=0; grid_j < 20; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        System.out.println(solve(grid));
    }

    private static long solve(int [][] grid){
        long best = 0;
        int [][] incs = {{1,0}, {0,1}, {1,1}, {1, -1}};
        for(int r = 0; r < 20; r++)
            for(int c = 0; c < 20; c++)
                for(int inc = 0; inc < 4; inc++)
                    best = Math.max(best, calc(grid, r, c, incs[inc][0], incs[inc][1]));
        return best;
    }

    private static long calc(int [][] grid, int r, int c, int rInc, int cInc){
        if(r + 3*rInc >= 20) return 0;
        if(c + 3*cInc >= 20 || c + 3*cInc < 0) return 0;
        long prod = 1;
        for(int i = 0; i < 4; i++)
            prod *= grid[r+i*rInc][c+i*cInc];
        return prod;
    }
}
