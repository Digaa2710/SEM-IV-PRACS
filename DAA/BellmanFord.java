import java.util.*;

public class BellmanFord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int source = 0;
        System.out.println("Enter number of vertices:");
        int n = sc.nextInt();
        int[] distance = new int[n];
        int[] parent = new int[n];
        int[][] map = new int[n][n];
        System.out.println("Enter weigths:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt();
            }
            System.out.println(" ");
        }
        distance[0] = 0;
        for (int i = 1; i < n; i++) {
            distance[i] = 100;
            parent[i] = -9999;
        }
        int k = 0;
        while (k < n - 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[j][i] != 0) {
                        if (distance[i] >= distance[j] + map[j][i]) {
                            distance[i] = distance[j] + map[j][i];
                            parent[i] = j;
                        }
                    }
                }
            }
            k++;
        }
        // to check further relaxation is possible or not
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != 0) {
                    if (distance[j] >= distance[i] + map[i][j]) {
                        System.out.println("The graph has a negative cycle");
                        return;
                    }
                }
            }
        }
        System.out.println("The graph does not have a negative cycle");
        for (int i = 0; i < n; i++) {
            System.out.println("Distance" + " " + distance[i] + " " + "Parent" + " " + parent[i]);
        }
    }
}
