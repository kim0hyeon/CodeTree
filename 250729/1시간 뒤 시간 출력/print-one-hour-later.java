import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        String arr[] = s.split(":");
        int h = Integer.parseInt(arr[0])+1;
        int m = Integer.parseInt(arr[1]);

        System.out.print(h+":"+m);
    }
}