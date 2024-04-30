import java.util.*;

public class SSTF {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter number of elements in queue");
        n = sc.nextInt();
        int[] queue = new int[n];
        boolean[] visited = new boolean[n];
        System.out.println("Enter head element");
        int head = sc.nextInt();

        queue[0] = head;
        visited[0] = true; // Mark the head as visited

        System.out.println("Enter queue elements");
        for (int i = 1; i < n; i++) {
            queue[i] = sc.nextInt();
        }

        int total_count = 0;
        int operand1 = 0;
        int operand2 = 0;
        int count = 0;
        int i = 0;
        while (count != n - 1) {

            int min = 1000;
            operand1 = 0;
            operand2 = 0;
            int k = 0;

            for (int j = 1; j < n; j++) {
                if (i != j && !visited[j]) {
                    int diff = Math.abs(queue[i] - queue[j]);
                    if (min > diff) {
                        min = diff;
                        operand1 = queue[i];
                        operand2 = queue[j];
                        k = j;
                    }
                }
            }

            visited[k] = true;
            total_count += Math.abs(operand1 - operand2);
            System.out.println(total_count);
            i = k;
            count++;
        }

        System.out.println("Total head movement: " + total_count);

    }
}
