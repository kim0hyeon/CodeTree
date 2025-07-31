import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[10];
        double count = 0;

        for (int i = 0; i < 10; i++){
            int a = sc.nextInt();
            if (a >= 250) break;
            arr[i] = a;
            count++;
        }

        System.out.printf("%d %.1f", Arrays.stream(arr).sum(), Arrays.stream(arr).sum() / count);
    }
}