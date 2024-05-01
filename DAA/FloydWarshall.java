import java.util.*;

public class FloydWarshall {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of times to check:");
        int n = sc.nextInt();

        int[][] map = new int[n][n];
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt();
            }
            System.out.println(" ");
        }
        int[][] parent = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != 0 && map[i][j] != 1000) {
                    parent[i][j] = i + 1;
                } else {
                    parent[i][j] = -1;
                }
            }
        }

        int k = 0;
        int a, b;
        int temp;
        while (k < 4) {

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    a = map[i][j];
                    temp = a;
                    b = map[i][k] + map[k][j];
                    int min = (a < b) ? a : b;
                    map[i][j] = min;
                    if (temp != map[i][j]) {
                        parent[i][j] = k + 1;
                    }
                }
            }
            k++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println(" ");
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(parent[i][j] + " ");
            }
            System.out.println(" ");
        }
    }

}
