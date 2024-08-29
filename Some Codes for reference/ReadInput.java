import java.util.*;

public class ReadInput {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine(); // 1 2 3 4 5

		String[] numbers = input.split(" ");
		int n = numbers.length;
		// for(int i = 0; i < n; i++) {
		// 		System.out.print(numbers[i] + " ");
		// }
		// ["1", "2", "3", "4", "5"]
		int[] intNumbers = new int[n];

		for (int i = 0; i < n; i++) {
			intNumbers[i] = Integer.parseInt(numbers[i]);
		}
		for (int i = 0; i < n; i++) {
			System.out.print(intNumbers[i] + " ");
		}
		// [1, 2, 3, 4, 5]
	}
}
