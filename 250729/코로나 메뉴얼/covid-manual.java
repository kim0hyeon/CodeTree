import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ans = 0;

        for (int i = 0; i < 3; i++){
            String s = sc.next();
            int a = sc.nextInt();

            if (s.equals("Y") && a >= 37)
                ans++;
            
        }

        if (ans >= 2)
            System.out.print("E");
        else
            System.out.print("N");
    }
}