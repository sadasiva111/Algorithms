import java.util.*;

class BinarySearch{
    public static void binarySearch(int arr[], int first, int last, int key){
        int mid = (first + last)/2;
        while( first <= last ){
            if ( arr[mid] < key ){
                first = mid + 1;
            }else if ( arr[mid] == key ){
                System.out.println("Element is found at index: " + mid);
                break;
            }else{
                last = mid - 1;
            }
            mid = (first + last)/2;
        }
        if ( first > last ){
            System.out.println("Element is not found!");
        }
    }
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        System.out.print("Number of Values : ");
        int n = input.nextInt();
        System.out.println("Enter the Values in order : ");
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }
        //Arrays.sort(array); [IF ORDER IS NOT PRESENT]
        System.out.print("Enter the Value to search : ");
        int key = input.nextInt();
        binarySearch(array,0,n-1,key);
    }
}  