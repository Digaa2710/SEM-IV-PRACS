import java.util.*;

public class Bankers {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int processes;
        boolean canAllocate;
        System.out.println("Enter processes:");
        processes = sc.nextInt();
        int resources;
        System.out.println("Enter resources:");
        resources = sc.nextInt();
        int[][] allocation = new int[processes][resources];
        int[][] max = new int[processes][resources];
        int[][] need = new int[processes][resources];
        int[] available = new int[resources];
        boolean[] visited = new boolean[processes];
        int[] allocated_processes = new int[processes];
        System.out.println("Enter allocated resources:");
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                allocation[i][j] = sc.nextInt();
            }

        }
        System.out.println("Allocates resources are:");
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                System.out.print(allocation[i][j] + " ");
            }
            System.out.println(" ");
        }
        System.out.println("Enter maximum resources");
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                max[i][j] = sc.nextInt();
            }
        }
        System.out.println("Need is:");
        for (int i = 0; i < processes; i++) {
            for (int j = 0; j < resources; j++) {
                need[i][j] = max[i][j] - allocation[i][j];
                System.out.print(need[i][j] + " ");
            }
            System.out.println(" ");
        }
        System.out.println("Enter available:");
        for (int i = 0; i < resources; i++) {
            available[i] = sc.nextInt();
            System.out.print(available[i] + " ");
        }
        System.out.println(" ");
        int k = 0;
        // for checking resources
        for (int i = 0; i < processes; i++) {
            canAllocate = true;
            visited[i] = true;
            for (int j = 0; j < resources; j++) {
                if (need[i][j] > available[j]) {
                    canAllocate = false;
                    visited[i] = false;
                    break;
                }
            }
            if (canAllocate) {
                for (int j = 0; j < resources; j++) {
                    available[j] += allocation[i][j];

                }
                allocated_processes[k] = i;
                k++;

            }
        }
        for (int i = 0; i < processes; i++) {
            if (!visited[i]) {
                for (int j = 0; j < resources; j++) {

                    available[j] += allocation[i][j];

                }
                allocated_processes[k] = i;
                k++;
            }
        }
        for (int i = 0; i < resources; i++) {
            System.out.print(available[i] + " ");

        }
        System.out.println(" ");
        for (int i = 0; i < k; i++) {
            System.out.println("Processes will be allocated in following manner:" + allocated_processes[i] + " ");
        }

    }
}
