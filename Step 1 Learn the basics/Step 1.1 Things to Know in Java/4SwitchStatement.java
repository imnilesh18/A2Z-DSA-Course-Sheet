public class Solution {
    public static double areaSwitchCase(int ch, double[] a) {
        double area = 0.0; // Initialize the area variable

        switch (ch) {
            case 1:
                area = Math.PI * a[0] * a[0]; // Calculate the area of a circle
                break;
            case 2:
                area = a[0] * a[1]; // Calculate the area of a rectangle
                break;
        }

        return area; // Return the calculated area
    }
}
