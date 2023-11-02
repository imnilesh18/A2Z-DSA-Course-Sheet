import java.util.*;
public class Solution {
        public static int[] getFrequencies(int []v) {
                int n =  v.length;
                // Create a HashMap to store the frequencies of elements.
                Map<Integer, Integer> frequencyMap = new HashMap<>();

                // Iterate through the array to calculate frequencies.
                for (int i = 0; i < n; i++) {
                        int num = v[i];
                        frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
                }

                int highestFrequency = 0;
                int lowestFrequency = n;
                int highestFrequencyElement = 0;
                int lowestFrequencyElement = Integer.MAX_VALUE;

                // Iterate through the frequency map to find the highest and lowest frequency elements.
                for (Map.Entry<Integer, Integer> entry : frequencyMap.entrySet()) {
                        int element = entry.getKey();
                        int frequency = entry.getValue();

                        if (frequency > highestFrequency || (frequency == highestFrequency && element < highestFrequencyElement)) {
                                highestFrequency = frequency;
                                highestFrequencyElement = element;
                        }

                        if (frequency < lowestFrequency || (frequency == lowestFrequency && element < lowestFrequencyElement)) {
                                lowestFrequency = frequency;
                                lowestFrequencyElement = element;
                        }
                }

                return new int[]{highestFrequencyElement, lowestFrequencyElement};
        }
}