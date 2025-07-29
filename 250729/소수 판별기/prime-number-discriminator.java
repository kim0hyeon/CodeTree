import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        boolean flag = true;

        for (int i = 2; i < n; i++){
            if (n%i == 0){
                flag = false;
                break;
            }
        }

        if (flag)
            System.out.println("P");
        else
            System.out.println("C");
    }
}