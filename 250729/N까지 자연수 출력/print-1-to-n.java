import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int target = sc.nextInt();
        int n = 1;
        
        while (n <= target)
            System.out.print((n++) + " ");
    }
}