import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int h = sc.nextInt();
        int w = sc.nextInt();

        int b = (w*10000)/(h*h);
        System.out.println(b);

        if (b >= 25){
            System.out.print("Obesity");
        }
    }
}