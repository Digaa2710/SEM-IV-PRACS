public class Prim {
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
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        distance[0] = 0;
        for (int i = 1; i < n; i++) {
            distance[i] = 100;
            parent[i] = -9999;
        }

        int k = 0;
        int index = 0;
        int[] min_arr = new int[n];
        while (k < n) {
            int min = 1000;

            for (int i = 0; i < n; i++) {
                if (!visited[index] && map[index][i] != 0) {
                    if (distance[i] >= distance[index] + map[index][i]) {
                        distance[i] = distance[index] + map[index][i];
                        parent[i] = index;
                        min_arr[i] = distance[i];

                    }

                }

            }
            visited[index] = true;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && min > min_arr[i]) {
                    min = min_arr[i];
                    index = i;
                }
            }

            k++;
        }

        for (int i = 0; i < n; i++) {
            System.out.println("Distance" + " " + distance[i] + " " + "Parent" + " " + parent[i]);
        }

    }
}
