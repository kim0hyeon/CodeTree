import java.util.Scanner;

class IntWrapper {
    int value;

    IntWrapper(int a){
        this.value = a;
    }
}

public class Main {

    public static void swap(IntWrapper a, IntWrapper b){
        int tmp = a.value;
        a.value = b.value;
        b.value = tmp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        IntWrapper a = new IntWrapper(n);
        IntWrapper b = new IntWrapper(m);

        swap(a, b);

        System.out.print(a.value + " " + b.value);
    }
}