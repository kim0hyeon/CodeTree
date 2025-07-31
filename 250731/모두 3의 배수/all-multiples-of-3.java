import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        boolean flag = true;
        for (int i = 0; i < 5; i++){
            int a = sc.nextInt();
            if (a % 3 != 0){
                System.out.print(0);
                return;
            }
        }
        System.out.print(1);
        return;
    }
}