public class Solution {
    public static int dataTypes(String type) {
        // Checking 'type' with all the data types we know.

        if (type.equals("Integer"))
            return 4;
        else if (type.equals("Long"))
            return 8;
        else if (type.equals("Float"))
            return 4;
        else if (type.equals("Double"))
            return 8;
        else if (type.equals("Character"))
            return 1;
        else // 'type' should have matched with some data type above
            return -1; // Should not be returned
    }
}
