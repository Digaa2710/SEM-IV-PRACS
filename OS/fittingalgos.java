import java.util.*;

public class fittingalgos {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] blocks = new int[5];
        int[] memory = new int[4];
        int[] sub = new int[5];
        boolean[] usedBlocks = new boolean[5];

        System.out.println("Enter block difference:");
        for (int i = 0; i < 5; i++) {
            blocks[i] = sc.nextInt();
        }
        System.out.println("Enter memory:");
        for (int i = 0; i < 4; i++) {
            memory[i] = sc.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            int min = 1000;
            int index = -1;
            for (int j = 0; j < 5; j++) {
                if (!usedBlocks[j] && blocks[j] >= memory[i]) {

                    sub[j] = blocks[j] - memory[i];
                    if (min > sub[j]) {
                        min = sub[j];
                        index = j + 1;
                    }
                }
            }
            if (index != -1) {
                System.out.println(memory[i] + " " + "goes to block" + " " + index);
                usedBlocks[index - 1] = true;
            }

        }
    }
}