import java.util.Scanner;
public class Main {

    public static void print(int[] arr, int n){
        for (int i = 0; i < n; i++){
            if (arr[i] % 2 == 0){
                System.out.print(arr[i]/2 + " ");
            } else{
                System.out.print(arr[i] + " ");
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        print(arr, n);
    }
}