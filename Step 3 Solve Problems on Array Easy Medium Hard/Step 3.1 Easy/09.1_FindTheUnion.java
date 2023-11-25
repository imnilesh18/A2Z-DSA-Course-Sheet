// Optimal Solution
import java.util.*;
public class Solution {
        public static ArrayList<Integer> sortedArray(int []a, int []b) {
                int n = a.length;
                int m = b.length;
                int i = 0, j = 0; // pointers
                ArrayList<Integer> Union = new ArrayList<>(); // Uninon vector
                while (i < n && j < m) {
                        if (a[i] <= b[j]) // Case 1 and 2
                        {
                                if (Union.size() == 0 || Union.get(Union.size()-1) != a[i])
                                        Union.add(a[i]);
                                i++;
                        }
                        else // case 3
                        {
                                if (Union.size() == 0 || Union.get(Union.size()-1) != b[j])
                                        Union.add(b[j]);
                                j++;
                        }
                }

                while (i < n) // IF any element left in arr1
                {
                        if (Union.get(Union.size()-1) != a[i])
                                Union.add(a[i]);
                        i++;
                }

                while (j < m) // If any elements left in arr2
                {
                        if (Union.get(Union.size()-1) != b[j])
                                Union.add(b[j]);
                        j++;
                }

                return Union;
        }
}


// Brute Force
import java.util.*;
public class Solution {
        public static ArrayList< Integer > sortedArray(int []a, int []b) {
                HashSet <Integer> s=new HashSet<>();
                ArrayList < Integer > Union=new ArrayList<>();
                for (int i = 0; i < a.length; i++)
                        s.add(a[i]);
                for (int i = 0; i < b.length; i++)
                        s.add(b[i]);
                for (int it: s)
                        Union.add(it);
                return Union;
        }
}