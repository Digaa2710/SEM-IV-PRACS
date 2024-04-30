import java.util.*;

class Job {
    public static void printanswer(int[] start, int[] end, int[] indices, int n) {

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                System.out.println("Job" + (i + 1));
            } else if (start[i + 1] >= end[i]) {
                System.out.println("Job" + (i + 2));
            }
        }
    }

    public static void sort(int[] end, int[] indices, int n) {
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (end[i] > end[j]) {
                    int temp = end[j];
                    end[j] = end[i];
                    end[i] = temp;

                    int tempIndex = indices[j];
                    indices[j] = indices[i];
                    indices[i] = tempIndex;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter the number of jobs:");
        n = sc.nextInt();
        int[] start = new int[n];
        int[] end = new int[n];
        int[] indices = new int[n]; // Array to store original indices
        System.out.println("Enter:");
        for (int i = 0; i < n; i++) {
            System.out.print("Enter start of job " + (i + 1) + ":");
            start[i] = sc.nextInt();
            System.out.print("Enter end of job " + (i + 1) + ":");
            end[i] = sc.nextInt();
        }
        sort(end, indices, n);
        printanswer(start, end, indices, n);
        // Print the sorted jobs with their original indices
        // System.out.println("Sorted jobs:");
        // for (int i = 0; i < n; i++) {
        // System.out.println("Job " + (indices[i] + 1) + ": start=" + start[indices[i]]
        // + ", end=" + end[i]);
        // }
    }
}

