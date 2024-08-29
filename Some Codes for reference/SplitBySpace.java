import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SplitBySpace {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String input = sc.nextLine();
        System.out.println("Input: " + input);
        ArrayList<String> result = new ArrayList<>();

        // Regex pattern to match words or quoted phrases with both double and single
        // quotes
        Pattern pattern = Pattern.compile("[^\\s\"']+|(['\"])(.*?)\\1");
        Matcher matcher = pattern.matcher(input);

        while (matcher.find()) {
            if (matcher.group(2) != null) {
                // If a quoted string is found, add the content inside the quotes (group 2)
                result.add(matcher.group(2));
            } else {
                // If a regular word is found, add it to the result
                result.add(matcher.group());
            }
        }

        // Print the result
        System.out.println(result);
    }
}
