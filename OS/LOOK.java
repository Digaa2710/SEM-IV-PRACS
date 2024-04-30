import java.util.*;

public class LOOK {
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

        System.out.println("Enter high/low (1 for high, 0 for low):");
        int choice = sc.nextInt();
        int total_count = 0;
        int current_head = head;
        if (choice == 1) {
            for (int i = 0; i < m; i++) {
                if (queue[i] >= head) {
                    total_count += Math.abs(queue[i] - current_head);
                    // System.out.println(total_count);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }
            for (int i = m - 1; i >= 0; i--) {
                if (!visited[i]) {
                    total_count += Math.abs(queue[i] - current_head);
                    // System.out.println(total_count);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }
        } else {
            for (int i = m - 1; i >= 0; i--) {
                if (queue[i] < head) {
                    total_count += Math.abs(queue[i] - current_head);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }
            for (int i = 0; i < m; i++) {
                if (!visited[i]) {
                    total_count += Math.abs(queue[i] - current_head);
                    current_head = queue[i];
                    visited[i] = true;
                }
            }
        }
        System.out.println("Total head movement is " + total_count);
    }
}

