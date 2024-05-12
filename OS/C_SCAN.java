import java.util.*;

public class C_SCAN {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int head;

        System.out.println("Enter head:");
        head = sc.nextInt();
        System.out.println("Enter number of elements:");
        int n = sc.nextInt();
        int m = n;
        int[] queue = new int[m];
        boolean[] visited = new boolean[m];
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            queue[i] = sc.nextInt();
        }
        Arrays.sort(queue); // Sorting the array
        visited[0] = true; // Marking the lowest disk number as visited

        System.out.println("Enter high/low (1 for high, 0 for low):");
        int choice = sc.nextInt();
        int total_count = 0;
        int current_head = head;

        if (choice == 1) {
            for (int i = 0; i < m; i++) {
                if (queue[i] >= head) {
                    total_count += Math.abs(queue[i] - current_head);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }

            // Wrap around to the lower end
            total_count += Math.abs(199 - current_head);
            current_head = 199;
            total_count += Math.abs(0 - current_head);
            current_head = 0;

            for (int i = 0; i < m; i++) {
                if (!visited[i]) {
                    total_count += Math.abs(queue[i] - current_head);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }
        } else {
            for (int i = m - 1; i >= 0; i--) {
                if (queue[i] <= head) {
                    total_count += Math.abs(queue[i] - current_head);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }

            // Wrap around to the higher end
            total_count += Math.abs(0- current_head);
            current_head = 0;
            total_count+=Math.abs(199-current_head);
            current_head=199;

            for (int i = m - 1; i >= 0; i--) {
                if (!visited[i]) {
                    total_count += Math.abs(queue[i] - current_head);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }
        }

        System.out.println("Total head movement: " + total_count);
    }
}
