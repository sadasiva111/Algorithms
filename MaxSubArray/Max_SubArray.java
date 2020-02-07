import java.util.Scanner;

public class Max_SubArray {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the size of array : ");
        int n = input.nextInt();
        int [] array = new int[n];
        System.out.println("Enter elements of array : ");
        for (int i = 0; i < n ; i++) {
            array[i] = input.nextInt();
        }
        int maxStartIndex=0;
        int maxEndIndex=0;
        int maxSum = Integer.MIN_VALUE;

        int cumulativeSum= 0;
        int maxStartIndexUntilNow=0;

        for (int currentIndex = 0; currentIndex < array.length; currentIndex++) {
            int eachArrayItem = array[currentIndex];
            cumulativeSum+=eachArrayItem;
            if(cumulativeSum>maxSum){
                maxSum = cumulativeSum;
                maxStartIndex=maxStartIndexUntilNow;
                maxEndIndex = currentIndex;
            }
            if (cumulativeSum<0){
                maxStartIndexUntilNow=currentIndex+1;
                cumulativeSum=0;
            }
        }
        System.out.println("Max sum       : "+maxSum);
        System.out.print("Max Sub Array : ");
        for (int i = maxStartIndex; i <=maxEndIndex ; i++) {
            System.out.print(array[i]+" ");
        }
      }
}