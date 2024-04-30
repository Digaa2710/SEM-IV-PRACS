import java.util.*;

public class FCSF {
    public static void main(String args[]) {
        int head;
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter number of elements in queue:");
        n = sc.nextInt();
        int[] queue = new int[n];
        System.out.println("Enter the queue elements:");
        for (int i = 0; i < n; i++) {
            queue[i] = sc.nextInt();
        }
        System.out.println("Enter head element:");
        head = sc.nextInt();
        int total_count = 0;
        if (head > queue[0]) {
            total_count = total_count + (head - queue[0]);
            // System.out.println(total_count);
        } else {
            total_count = total_count + (queue[0] - head);
            // System.out.println(total_count);
        }
        for (int i = 0; i < n - 1; i++) {

            if (queue[i + 1] >= queue[i]) {
                total_count = total_count + (queue[i + 1] - queue[i]);
                // System.out.println(total_count);
            } else if (queue[i] > queue[i + 1]) {
                total_count = total_count + (queue[i] - queue[i + 1]);
                // System.out.println(total_count);
            }

        }
        System.out.println("Total heads" + total_count);

    }
}
