import java.util.*;

public class Optimal {
    public static void main(String args[]) {
        int[] arr = { 4, 7, 3, 0, 1, 7, 3, 8, 5, 4, 5, 3, 4, 7 };
        int capacity = 3;
        int miss = 0;
        int hit = 0;
        int[] sol_arr = new int[capacity];
        int[] index = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            sol_arr[i] = -1;
        }

        for (int i = 0; i < arr.length; i++) {

            boolean found = false;
            for (int j = 0; j < capacity; j++) {
                // Check if the page is already in memory
                if (sol_arr[j] == arr[i]) {
                    hit++;
                    index[j] = i + 1; // Update index of current reference
                    found = true;
                    System.out.println("Step " + (i + 1) + ": Element " + arr[i] + " found in memory at index " + j
                            + " (Hit)");
                    break;
                }
            }
            if (!found) {
                // Find the page to replace using Optimal Page Replacement Algorithm
                int farthestIndex = -1;
                int pageToReplace = -1;
                for (int j = 0; j < capacity; j++) {
                    boolean foundFutureReference = false;
                    for (int k = i + 1; k < arr.length; k++) {
                        if (sol_arr[j] == arr[k]) {
                            index[j] = k + 1; // Update index of future reference
                            foundFutureReference = true;
                            break;
                        }
                    }
                    if (!foundFutureReference) {
                        pageToReplace = j;
                        break;
                    } else {
                        if (index[j] > farthestIndex) {
                            farthestIndex = index[j];
                            pageToReplace = j;
                        }
                    }
                }

                // Replace the page
                sol_arr[pageToReplace] = arr[i];
                index[pageToReplace] = i + 1;
                miss++;
                System.out.println("Step " + (i + 1) + ": Element " + arr[i] + " inserted into memory at index "
                        + pageToReplace + " (Miss)");
            }

        }

        System.out.println("Total Misses: " + miss);
        System.out.println("Total Hits: " + hit);
    }
}
