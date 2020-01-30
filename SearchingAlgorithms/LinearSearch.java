import java.util.Scanner;

public class LinearSearch {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Number of Values : ");
        int n = input.nextInt();
        System.out.println("Enter the Values : ");
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }
        System.out.print("Enter the Value to search : ");
        int key = input.nextInt();
        int x = n+1;
        for (int i = 0; i < n; i++) {
            if (array[i] == key) {
                x = i;
            }
        }
        if (x == n+1) System.out.println("Key Value Not Found");
        else System.out.println("Key Value found at index " + x);
    }
}