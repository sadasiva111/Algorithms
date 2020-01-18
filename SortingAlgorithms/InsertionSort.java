

import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Number of values : ");
        int n=input.nextInt();
        int []a= new int [n];
        System.out.print("Enter the values :");
        for (int i = 0; i <n ; i++) {
            a[i]=input.nextInt();
        }
        int j,temp;
        for (int i = 0; i < n ; i++) {

            temp=a[i];
            for (j = i-1; j>=0 && temp<=a[j] ; j--) {
                a[j+1]=a[j];
            }
            a[j+1]= temp;
        }
        System.out.println("Sorted Values:");
        for (int i = 0; i <n ; i++) {
            System.out.print(a[i]+" ");
        }
    }
}
