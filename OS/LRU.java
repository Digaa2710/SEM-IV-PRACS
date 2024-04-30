import java.util.*;

class LRU_ALGO {
    void calculate() {
        int n;
        System.out.println("Enter number of values:");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements of array:");
        for (int k = 0; k < n; k++) {
            arr[k] = sc.nextInt();
        }
        int capacity;
        System.out.println("Enter capacity:");
        capacity = sc.nextInt();

        int miss = 0;
        int hit = 0;
        int[] sol_arr = new int[capacity];
        int[] index = new int[capacity];
        int i;
        for (i = 0; i < n; i++) {
            // this if for starting 'capacity' values
            if (i < capacity) {
                sol_arr[i] = arr[i];
                index[i] = i + 1;
                miss = miss + 1;
                System.out.println("Step " + (i + 1) + ": Element " + arr[i] + " inserted into array at index " + i);
            } else {
                boolean found = false;
                for (int j = 0; j < capacity; j++) {
                    // this is for hit condition
                    if (sol_arr[j] == arr[i]) {
                        hit++;
                        index[j] = i + 1;
                        found = true;
                        System.out
                                .println("Step " + (i + 1) + ": Element " + arr[i] + " found at index " + j + " (Hit)");
                        break;
                    }
                }
                // this is for replacing
                if (!found) {
                    int min = 1000;
                    int minIndex = -1;
                    for (int j = 0; j < capacity; j++) {
                        if (min > index[j]) {
                            minIndex = j;
                            min = index[j];
                        }
                    }
                    sol_arr[minIndex] = arr[i];
                    index[minIndex] = i + 1;
                    miss++;
                    System.out.println("Step " + (i + 1) + ": Element " + arr[i] + " inserted into array at index "
                            + minIndex + " (Miss)");
                }
            }

        }
        System.out.println("Total Misses: " + miss);
        System.out.println("Total Hits: " + hit);

    }
}

public class LRU {
    public static void main(String args[]) {
        LRU_ALGO a = new LRU_ALGO();
        a.calculate();
    }
}
