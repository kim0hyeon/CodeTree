import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int ans = 1;
        for (int i = 1; i <= 10; i++){
            ans *= i;
            if (ans >= n){
                System.out.println(i);
                return;
            }
        }
    }
}