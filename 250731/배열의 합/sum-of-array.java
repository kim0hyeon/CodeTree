import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] arr = new int[4][4];
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                arr[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < 4; i++){
            System.out.println(Arrays.stream(arr[i]).sum());
        }
    }
}