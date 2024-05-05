// Leetcode:
class Solution {
    public List<Integer> generateRow(int row){
        long ans = 1;
        List<Integer> ansRow = new ArrayList<>();
        ansRow.add(1); //inserting the 1st element

        //calculate the rest of the elements:
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.add((int)ans);
        }
        return ansRow;

    }

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> temp = new ArrayList<>();

        //store the entire pascal's triangle:
        for(int row = 1; row <= numRows; row++){
            temp.add(generateRow(row));
        }
        return temp;
    }
}

// Coding Ninjas
import java.util.*;
public class Solution {
    public static int[] generateRows(int row){
        long ans = 1;
        int[] ansRow = new int[row];
        ansRow[0] = 1; //inserting the 1st element

        //calculate the rest of the elements:
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans/ col;
            ansRow[col] = (int) ans;
        }
        return ansRow;

    }
    public static int[][] pascalTriangle(int N) {
        int[][] temp = new int[N][];

        //store the entire pascal's triangle:
        for(int row = 0; row < N; row++){ // Array index starts from 0 that's why here we have to run loop from 0
            temp[row] = generateRows(row+1);
        }
        return temp;
    }
}