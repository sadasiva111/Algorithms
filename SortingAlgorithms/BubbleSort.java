import java.util.Scanner;

public class BubbleSort {

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements : ");
        int n = input.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter " + n + " elements :");
        for (int i = 0; i < n; i++)
            arr[i] = input.nextInt();
        bubbleSort(arr);
        System.out.println("The sorted array :");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
   
    }
    static void bubbleSort(int arr[]) {
        int len = arr.length, temp;
        for (int i = 0; i < len; i++) {
           
            for (int j = 0; j < len - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                   
                }
            }
        }
    }
}
