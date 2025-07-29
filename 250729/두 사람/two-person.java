import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a_age, b_age;
        String a_gen, b_gen;

        Scanner sc = new Scanner(System.in);

        a_age = sc.nextInt();
        a_gen = sc.next();
        b_age = sc.nextInt();
        b_gen = sc.next();

        if ((a_age >= 19 && a_gen.equals("M")) || (b_age >= 19 && b_gen.equals("M"))){
            System.out.print(1);
        }
        else{
            System.out.print(0);
        }
    }
}